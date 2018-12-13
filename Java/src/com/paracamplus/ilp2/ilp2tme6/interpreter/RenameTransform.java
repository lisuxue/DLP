package com.paracamplus.ilp2.ilp2tme6.interpreter;

import com.paracamplus.ilp1.compiler.normalizer.INormalizationEnvironment;
import com.paracamplus.ilp1.compiler.normalizer.NoSuchLocalVariableException;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interfaces.IASTblock.IASTbinding;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp2.interfaces.IASTfactory;
import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;

public class RenameTransform extends CopyTransform<INormalizationEnvironment> {

	private int cptvar = 0 ;
	public RenameTransform(IASTfactory factory) {
		super(factory);
		// TODO Auto-generated constructor stub
	}
	
	public IASTfunctionDefinition visit(IASTfunctionDefinition iast, INormalizationEnvironment lexenv) 
            throws EvaluationException {
		
		IASTvariable[] newVariables = new IASTvariable[iast.getVariables().length]; // newvariables
		INormalizationEnvironment newNormEnv = lexenv; // nouvel env
		
		// Args
		for (int i = 0 ; i < iast.getVariables().length; ++i) {
			IASTvariable v = iast.getVariables()[i];
			IASTvariable var = factory.newVariable(v.getName()+"_"+cptvar++);
			
			newVariables[i] = var;
			newNormEnv = newNormEnv.extend(v, var);
		}
		
        return factory.newFunctionDefinition(iast.getFunctionVariable(), newVariables,
                                     iast.getBody().accept(this, newNormEnv));
    }
	
	@Override
	public IASTexpression visit(IASTblock iast, INormalizationEnvironment lexenv) throws EvaluationException {
		
			INormalizationEnvironment newNormEnv = lexenv; // nouvel env
			
			IASTbinding[] bindings = new IASTbinding[iast.getBindings().length]; // binding (argument pour le newblock)
			
			for (int i = 0 ; i < iast.getBindings().length; ++i) {
				IASTvariable v = iast.getBindings()[i].getVariable();
				IASTvariable var = factory.newVariable(v.getName()+"_"+cptvar++);
				
				bindings[i] = factory.newBinding(var, iast.getBindings()[i].getInitialisation().accept(this, lexenv));
				newNormEnv = newNormEnv.extend(v, var);
			}	
			
			return factory.newBlock(iast.getBindings(), iast.getBody().accept(this, newNormEnv));
	}
	

	
    @Override
	public IASTexpression visit(IASTvariable iast, INormalizationEnvironment lexenv) 
            throws EvaluationException {
    	try {
    		return lexenv.renaming(iast);
    	} catch (NoSuchLocalVariableException e) {
    		return iast;
    	}   	
    }

}
