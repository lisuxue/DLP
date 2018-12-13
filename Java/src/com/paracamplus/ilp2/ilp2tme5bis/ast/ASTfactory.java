/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme5bis.ast;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp2.ast.ASTassignment;
import com.paracamplus.ilp2.ast.ASTfunctionDefinition;
import com.paracamplus.ilp2.ast.ASTprogram;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTbreak;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTcontinue;
import com.paracamplus.ilp2.ilp2tme5bis.interfaces.IASTfactory;
import com.paracamplus.ilp2.interfaces.IASTassignment;
import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;
import com.paracamplus.ilp2.interfaces.IASTprogram;



public class ASTfactory extends com.paracamplus.ilp2.ast.ASTfactory 
	implements IASTfactory{

    @Override
	public IASTprogram newProgram(IASTfunctionDefinition[] functions, 
                                  IASTexpression expression) {
        return new ASTprogram(functions, expression);
    }
    

    @Override
	public IASTassignment newAssignment(IASTvariable variable,
                                        IASTexpression value) {
        return new ASTassignment(variable, value);
    }


    @Override
	public IASTfunctionDefinition newFunctionDefinition(
            IASTvariable functionVariable,
            IASTvariable[] variables, 
            IASTexpression body) {
        return new ASTfunctionDefinition(functionVariable, variables, body);
    }


	@Override
	public IASTexpression newLoop(String label, IASTexpression condition, IASTexpression body) {
		return new ASTloop(label,condition,body);
	}


	@Override
	public IASTbreak newBreak(String label) {
		return new ASTbreak(label);
	}


	@Override
	public IASTcontinue newContinue(String label) {
		return new ASTcontinue(label);
	}

}
