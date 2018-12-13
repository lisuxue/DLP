/* *****************************************************************
 * ilp3 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp3
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp3.ilp3tme7.interpreter;

import com.paracamplus.ilp3.ilp3tme7.interfaces.IASTcostart;
import com.paracamplus.ilp3.ilp3tme7.interfaces.IASTvisitor;

import java.util.List;
import java.util.Vector;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.Invocable;

public class Interpreter extends com.paracamplus.ilp3.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> {
    
	 public Interpreter(IGlobalVariableEnvironment globalVariableEnvironment,
				IOperatorEnvironment operatorEnvironment) {
			super(globalVariableEnvironment, operatorEnvironment);
		}

	@Override
	public Object visit(IASTcostart iast, ILexicalEnvironment lexenv) throws EvaluationException {
		
		Object function = iast.getCoroutine().accept(this, lexenv);
        if ( function instanceof Invocable ) {
            Invocable f = (Invocable)function;
            List<Object> args = new Vector<Object>();
            for ( IASTexpression arg : iast.getArguments() ) {
                Object value = arg.accept(this, lexenv);
                args.add(value);
            }
            CoroutineInstance coi = new CoroutineInstance(f, args, this);
            coi.start();
            return coi;
        } else {
            String msg = "Cannot apply " + function;
            throw new EvaluationException(msg);
        }
	}


   
}
