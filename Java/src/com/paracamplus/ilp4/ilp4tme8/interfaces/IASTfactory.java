/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.interfaces;

import com.paracamplus.ilp1.interfaces.IASTexpression;


public interface IASTfactory extends com.paracamplus.ilp4.interfaces.IASTfactory {

	IASTexpression newReadProperty(IASTexpression prop, IASTexpression target);
	IASTexpression newWriteProperty(IASTexpression prop, IASTexpression target,IASTexpression value);
	IASTexpression newHasProperty(IASTexpression prop, IASTexpression target);
	


}
