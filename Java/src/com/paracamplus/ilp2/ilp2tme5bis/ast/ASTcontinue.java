package com.paracamplus.ilp2.ilp2tme5bis.ast;

import com.paracamplus.ilp1.annotation.OrNull;
import com.paracamplus.ilp1.ast.ASTexpression;
import com.paracamplus.ilp1.interfaces.IASTvisitable;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTcontinue;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTvisitor;

public class ASTcontinue extends ASTexpression implements IASTcontinue, IASTvisitable {
	
	private String label;

	public ASTcontinue (String label) {
		this.label = label;
	}

	@Override @OrNull
	public String getLabel() {
		return label;
	}
	
	@Override
	public boolean isLabelled () {
	    return this.label != null;
	}
	
	@Override
	public <Result, Data, Anomaly extends Throwable> Result accept(
			com.paracamplus.ilp1.interfaces.IASTvisitor<Result, Data, Anomaly> visitor, Data data) throws Anomaly {
		return ((IASTvisitor <Result, Data, Anomaly>) visitor).visit(this, data);
	}

}
