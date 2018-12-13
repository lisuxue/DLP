/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme6.interpreter;

import java.util.List;
import java.util.Vector;

import com.paracamplus.ilp2.interfaces.IASTassignment;
import com.paracamplus.ilp2.interfaces.IASTloop;
import com.paracamplus.ilp2.interfaces.IASTvisitor;//modifier
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp2.interfaces.IASTprogram;
import com.paracamplus.ilp1.interfaces.IASTsequence;
import com.paracamplus.ilp1.interfaces.IASTstring;
import com.paracamplus.ilp1.interfaces.IASTunaryOperation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interfaces.IASTalternative;
import com.paracamplus.ilp1.interfaces.IASTbinaryOperation;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTboolean;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTfloat;
import com.paracamplus.ilp1.interfaces.IASTinteger;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp2.interfaces.IASTfactory;//modifier

public class CopyTransform<Data> implements IASTvisitor<IASTexpression, Data, EvaluationException> {

	protected IASTfactory factory;
	
	
	public IASTprogram visit(IASTprogram iast, Data data) throws EvaluationException {
		//System.out.println(factory.newProgram(iast.getBody().getClass()));
        return (IASTprogram) factory.newProgram(iast.getBody().accept(this, data));
    }
	
	public IASTprogram visit(IASTprogram iast) throws EvaluationException {
		//System.out.println(factory.newProgram(iast.getBody().getClass()));
        return (IASTprogram) factory.newProgram(iast.getBody().accept(this,null));
    }
	
	public CopyTransform(IASTfactory factory) {
		this.factory = factory ;
	}
	
	@Override
	public IASTexpression visit(IASTassignment iast, Data data) throws EvaluationException {
		return factory.newAssignment(iast.getVariable(), iast.getExpression().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTloop iast, Data data) throws EvaluationException {
		return factory.newLoop(iast.getCondition().accept(this, data), iast.getBody().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTalternative iast, Data data) throws EvaluationException {
		return factory.newAlternative(
				iast.getCondition().accept(this, data),
				iast.getConsequence().accept(this, data), 
				iast.getAlternant() == null ? null : iast.getAlternant().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTbinaryOperation iast, Data data) throws EvaluationException {
		return factory.newBinaryOperation(iast.getOperator(), 
				iast.getLeftOperand().accept(this, data),
				iast.getRightOperand().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTblock iast, Data data) throws EvaluationException {
		return factory.newBlock(iast.getBindings(), iast.getBody().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTboolean iast, Data data) throws EvaluationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTfloat iast, Data data) throws EvaluationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTinteger iast, Data data) throws EvaluationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTinvocation iast, Data data) throws EvaluationException {
		 List<IASTexpression> args = new Vector<IASTexpression>();
         for ( IASTexpression arg : iast.getArguments() )
        	 args.add(arg.accept(this, data));
		return factory.newInvocation(iast.getFunction().accept(this, data),
				args.toArray(new IASTexpression[args.size()]));
	}

	@Override
	public IASTexpression visit(IASTsequence iast, Data data) throws EvaluationException {
		List<IASTexpression> exprs = new Vector<IASTexpression>();
        for ( IASTexpression expr : iast.getExpressions() )
       	 exprs.add(expr.accept(this, data));
		return factory.newSequence(exprs.toArray(new IASTexpression[exprs.size()]));
	}

	@Override
	public IASTexpression visit(IASTstring iast, Data data) throws EvaluationException {
		return factory.newStringConstant(iast.getValue());
	}

	@Override
	public IASTexpression visit(IASTunaryOperation iast, Data data) throws EvaluationException {
		return factory.newUnaryOperation(iast.getOperator(), iast.getOperand().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTvariable iast, Data data) throws EvaluationException {
		return factory.newVariable(iast.getName());
	}

    

}