/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme4.ex3.interpreter;

import com.paracamplus.ilp2.ilp2tme4.ex3.interfaces.IASTunless;
import com.paracamplus.ilp2.ilp2tme4.ex3.interfaces.IASTvisitor;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;


public class Interpreter extends com.paracamplus.ilp2.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> {
    

    // 
    
    public Interpreter(IGlobalVariableEnvironment globalVariableEnvironment,
			IOperatorEnvironment operatorEnvironment) {
		super(globalVariableEnvironment, operatorEnvironment);
	}


    private static Object whatever = "whatever";
    
	@Override
	public Object visit(IASTunless iast, ILexicalEnvironment lexenv) throws EvaluationException {
		 Object c = iast.getCondition().accept(this, lexenv);
	        if ( c != null && c instanceof Boolean ) {
	            Boolean b = (Boolean) c;
	            if ( b.booleanValue() ) {
	            	return whatever;             
	            } else {
	            	return iast.getBody().accept(this, lexenv);
	            }
	        } else {
	            return iast.getBody().accept(this, lexenv);
	        }
	}
    
    


}
