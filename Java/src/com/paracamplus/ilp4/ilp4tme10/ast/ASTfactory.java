/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.ast;

import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTexists;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTfactory;

public class ASTfactory 
extends  com.paracamplus.ilp4.ast.ASTfactory
implements IASTfactory {

	@Override
	public IASTexists newExists(String varName) {
		return new ASTexists(varName);
	}

    
}
