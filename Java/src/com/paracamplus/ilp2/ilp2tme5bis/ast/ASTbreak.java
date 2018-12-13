package com.paracamplus.ilp2.ilp2tme5bis.ast;

import com.paracamplus.ilp1.annotation.OrNull;
import com.paracamplus.ilp1.ast.ASTexpression;
import com.paracamplus.ilp1.interfaces.IASTvisitable;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTbreak;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTvisitor;

public class ASTbreak extends ASTexpression implements IASTbreak, IASTvisitable {

	
	private String label;

	public ASTbreak (String label) {
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
