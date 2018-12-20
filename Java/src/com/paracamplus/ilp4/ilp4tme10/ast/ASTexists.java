/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.ast;

import com.paracamplus.ilp1.ast.ASTexpression;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTvisitor;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTexists;

public class ASTexists extends ASTexpression implements IASTexists{

	private final String varName;
	
	public ASTexists (String varName) {
        this.varName = varName;
    }
	
	@Override
	public <Result, Data, Anomaly extends Throwable> Result accept(com.paracamplus.ilp1.interfaces.IASTvisitor<Result, Data, Anomaly> visitor,
			Data data) throws Anomaly {
		// TODO Auto-generated method stub
		return ((IASTvisitor<Result, Data, Anomaly>) visitor).visit(this, data);
	}

	@Override
	public String getVarName() {
		return varName;
	}
    
   
   
}
