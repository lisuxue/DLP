/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme5.ast;

import com.paracamplus.ilp2.ilp2tme5.interfaces.IASTbreak;
import com.paracamplus.ilp2.ilp2tme5.interfaces.IASTcontinue;
import com.paracamplus.ilp2.ilp2tme5.interfaces.IASTfactory;




public class ASTfactory extends com.paracamplus.ilp2.ast.ASTfactory 
	implements IASTfactory{

	@Override
	public IASTcontinue newContinue() {
		return new ASTcontinue();
	}
	
    public IASTbreak newBreak() {
    	return new ASTbreak();
    }



    
    
}
