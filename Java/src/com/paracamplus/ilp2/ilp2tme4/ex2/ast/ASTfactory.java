/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme4.ex2.ast;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp2.ilp2tme4.ex2.interfaces.IASTunless;
import com.paracamplus.ilp2.interfaces.IASTfactory;




public class ASTfactory extends com.paracamplus.ilp2.ast.ASTfactory 
	implements IASTfactory{


    public IASTunless newUnless(IASTexpression condition, IASTexpression body) {
    	return new ASTunless(condition,body);
    }
}
