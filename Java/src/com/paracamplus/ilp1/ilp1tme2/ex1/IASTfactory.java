/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp1.ilp1tme2.ex1;

import org.antlr.v4.runtime.Token;

import com.paracamplus.ilp1.interfaces.IASTexpression;

import antlr4.ILPMLgrammar1tme2Parser.ExprContext;

public interface IASTfactory extends com.paracamplus.ilp1.interfaces.IASTfactory{

	IASTexpression newAffectation(Token var, ExprContext val);
 
   
}
