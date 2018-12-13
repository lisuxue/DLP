package com.paracamplus.ilp1.ilp1tme1.sequence;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;

public class ASTsequence extends com.paracamplus.ilp1.ast.ASTsequence implements com.paracamplus.ilp1.ilp1tme1.sequence.IASTsequence {

	public ASTsequence(IASTexpression[] expressions) {
		super(expressions);
		// TODO Auto-generated constructor stub
	}

	/*@Override
	public IASTexpression[] getExpressions() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public <Result, Data, Anomaly extends Throwable> Result accept(IASTvisitor<Result, Data, Anomaly> visitor,
			Data data) throws Anomaly {
		// TODO Auto-generated method stub
		return null;
	}*/

	@Override
	public IASTexpression[] getAllButLastInstructions() throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

}
