/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.ast;

import com.paracamplus.ilp1.ast.ASTexpression;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTreadProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTvisitor;

public class ASTreadProperty extends ASTexpression
implements IASTreadProperty {

    public ASTreadProperty (IASTexpression property, IASTexpression target) {
        this.property = property;
        this.target = target;
    }
    private final IASTexpression property;
    private final IASTexpression target;
    
    @Override
	public IASTexpression getTarget() {
        return target;
    }

    @Override
	public IASTexpression getProperty() {
        return property;
    }

    @Override
    public <Result, Data, Anomaly extends Throwable> Result accept(
			com.paracamplus.ilp1.interfaces.IASTvisitor<Result, Data, Anomaly> visitor,
			Data data) throws Anomaly {
        return ((IASTvisitor<Result, Data, Anomaly>) visitor).visit(this, data);
    }
}
