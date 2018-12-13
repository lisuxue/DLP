/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme5bis.interfaces;

	
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;
import com.paracamplus.ilp2.interfaces.IASTprogram;

public interface IASTfactory extends com.paracamplus.ilp2.interfaces.IASTfactory {
    IASTprogram newProgram(
    		IASTfunctionDefinition[] functions,
            IASTexpression expression);
    
    IASTexpression newLoop(String label,
    					   IASTexpression condition,
                           IASTexpression body);

    IASTfunctionDefinition newFunctionDefinition(
            IASTvariable functionVariable,
            IASTvariable[] variables,
            IASTexpression body);
    
    IASTexpression newAssignment(IASTvariable variable,
            IASTexpression value);
    
    IASTbreak newBreak(String label);
    IASTcontinue newContinue(String label);
}
