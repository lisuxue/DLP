/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme5.ast;

import com.paracamplus.ilp1.ast.ASTexpression;
import com.paracamplus.ilp2.ilp2tme5.interfaces.IASTvisitor;
import com.paracamplus.ilp2.ilp2tme5.interfaces.IASTbreak;

public class ASTbreak extends ASTexpression
implements IASTbreak {
    
	public ASTbreak() {}
	
    @Override
	public <Result, Data, Anomaly extends Throwable> 
    Result accept(com.paracamplus.ilp1.interfaces.IASTvisitor<Result, Data, Anomaly> visitor, Data data) 
    		throws Anomaly {
        return ((IASTvisitor<Result, Data, Anomaly>)visitor).visit(this, data);
    }
}
