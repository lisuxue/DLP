/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme5bis.interpreter;

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interpreter.EmptyLexicalEnvironment;
import com.paracamplus.ilp1.interpreter.Function;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.Invocable;
import com.paracamplus.ilp2.ilp2tme5bis.interpreter.exception.ContinueException;
import com.paracamplus.ilp2.ilp2tme5bis.interpreter.exception.BreakException;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTbreak;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTcontinue;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTloop;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTvisitor;
import com.paracamplus.ilp2.interfaces.IASTassignment;
import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;
import com.paracamplus.ilp2.interfaces.IASTprogram;


public class Interpreter extends com.paracamplus.ilp2.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> {
    

    // 
    private ArrayList<String> tabLabel;
    private int cptwhile;
	
    public Interpreter(IGlobalVariableEnvironment globalVariableEnvironment,
			IOperatorEnvironment operatorEnvironment) {
		super(globalVariableEnvironment, operatorEnvironment);
		this.tabLabel = new ArrayList<String>();
		this.cptwhile = 0;
	}

    @Override
	public Object visit(com.paracamplus.ilp1.interfaces.IASTprogram iast, ILexicalEnvironment lexenv) throws EvaluationException  {
    	return visit((IASTprogram)iast, lexenv);
    }

	public Object visit(IASTprogram iast, ILexicalEnvironment lexenv) 
            throws EvaluationException {
        for ( IASTfunctionDefinition fd : iast.getFunctionDefinitions() ) {
            Object f = this.visit(fd, lexenv);
            String v = fd.getName();
            getGlobalVariableEnvironment().addGlobalVariableValue(v, f);
        }
        try {
            return iast.getBody().accept(this, lexenv);
       } catch (Exception exc) {
            return exc;
        }
    }
   
    // 

            
    @Override
	public Object visit(IASTassignment iast, ILexicalEnvironment lexenv) 
            throws EvaluationException {
        IASTvariable variable = iast.getVariable();
        Object value = iast.getExpression().accept(this, lexenv);
        try {
            lexenv.update(variable, value);
        } catch (EvaluationException exc) {
            getGlobalVariableEnvironment()
                .updateGlobalVariableValue(variable.getName(), value);
        }
        return value;
    }


    
    public Invocable visit(IASTfunctionDefinition iast, ILexicalEnvironment lexenv) 
            throws EvaluationException {
        Invocable fun = new Function(iast.getVariables(),
                                     iast.getBody(),
                                     new EmptyLexicalEnvironment());
        return fun;
    }
    
    @Override
	public Object visit(IASTinvocation iast, ILexicalEnvironment lexenv) 
            throws EvaluationException {
        Object function = iast.getFunction().accept(this, lexenv);
        if ( function instanceof Invocable ) {
            Invocable f = (Invocable)function;
            List<Object> args = new Vector<Object>();
            for ( IASTexpression arg : iast.getArguments() ) {
                Object value = arg.accept(this, lexenv);
                args.add(value);
            }
            return f.apply(this, args.toArray());
        } else {
            String msg = "Cannot apply " + function;
            throw new EvaluationException(msg);
        }
    }
    
    
    @Override //////A MODIFIER pour prendre en cpt le label 
	public Object visit(IASTloop iast, ILexicalEnvironment lexenv) 
            throws EvaluationException {

    	if (iast.isLabelled()) {
    		String label = iast.getLabel();
    		tabLabel.add(label);
    	}
        while ( true ) {
            Object condition = iast.getCondition().accept(this, lexenv);
            if ( condition instanceof Boolean ) {
                Boolean c = (Boolean) condition;
                if ( ! c ) {
                    break;
                }
            }
          	
            cptwhile++;
            try {

            	iast.getBody().accept(this, lexenv);	

            }catch(ContinueException ce) {

            	String msg = ce.getMessage(); // retourne soit le nom d'un label soit le message "break simple"
            	if ((msg==iast.getLabel()) || msg=="continue simple") {
            		// on se trouve dans la bonne while pour faire un continue simple
            		tabLabel.remove(tabLabel.lastIndexOf(iast.getLabel()));
            		continue; 
            	}
            	// le continue est accompagné d'un label d'une while extérieure ou d'un label non existant.
            	int position = tabLabel.lastIndexOf(msg);
            	if (position == -1) throw new EvaluationException("Le label n'existe pas");
            	tabLabel.remove(tabLabel.lastIndexOf(iast.getLabel()));
            	cptwhile--;
            	throw new ContinueException(msg);
            	
            }catch(BreakException be) {
            	String msg = be.getMessage(); // retourne soit le nom d'un label soit le message "break simple"
            	System.out.println(msg); // voir ici : il faut d'abord verifier qu'il y a un label avant de pouvoir le recuperer 
            	if (msg=="break simple") {
            		// on se trouve dans la bonne while pour faire un continue simple
            		tabLabel.remove(tabLabel.lastIndexOf(iast.getLabel()));
            		break; 
            	}
            	if (iast.isLabelled()) {
            		String label = iast.getLabel();
            		if (label==msg) {
            			tabLabel.remove(tabLabel.lastIndexOf(iast.getLabel()));
            			break;
            		}else { //c'est que on a affaire à un break avec label qui est pas celui de la boucle en cours
            	
		            	// le break est accompagné d'un label d'une while extérieure ou d'un label non existant.
		            	int position = tabLabel.lastIndexOf(msg);
		            	if (position == -1) throw new EvaluationException("Le label n'existe pas");
		            	tabLabel.remove(tabLabel.lastIndexOf(iast.getLabel()));
		            	cptwhile--;
		            	throw new BreakException(msg);
            		}
            	}
            
            }
        }
        cptwhile--;
        return Boolean.FALSE;
    }

	@Override
	public Object visit(IASTbreak iast, ILexicalEnvironment data) throws EvaluationException {
		if (cptwhile<1) {
			throw new EvaluationException("break n'est pas dans une while");
		}else{
			if (iast.isLabelled()) { // break label
				String label = iast.getLabel();
				throw new BreakException(label);
			}else {
				throw new BreakException("break simple"); // break simple
			}
		}
	}

	@Override
	public Object visit(IASTcontinue iast, ILexicalEnvironment data) throws EvaluationException {
		if (cptwhile<1) {
			throw new EvaluationException("continue n'est pas dans une while");
		}else{
			if (iast.isLabelled()) { // break label
				String label = iast.getLabel();
				throw new ContinueException(label);
			}else {
				throw new ContinueException("continue simple"); // break simple
			}
		}
	}




}
