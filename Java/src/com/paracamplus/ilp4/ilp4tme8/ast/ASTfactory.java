/* *****************************************************************
 * ilp3 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp3
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.ast;


import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTfactory;

public class ASTfactory extends com.paracamplus.ilp4.ast.ASTfactory
implements IASTfactory{

	@Override
	public IASTexpression newReadProperty(IASTexpression prop, IASTexpression target) {
		return new ASTreadProperty(prop,target);
	}

	@Override
	public IASTexpression newWriteProperty(IASTexpression prop, IASTexpression target, IASTexpression value) {
		return new ASTwriteProperty(prop,target,value);
	}

	@Override
	public IASTexpression newHasProperty(IASTexpression prop, IASTexpression target) {
		return new ASThasProperty(prop,target);
	}



}
