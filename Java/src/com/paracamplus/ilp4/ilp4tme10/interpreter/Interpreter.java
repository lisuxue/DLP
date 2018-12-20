/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.interpreter;

import java.util.List;

import com.paracamplus.ilp1.ast.ASTvariable;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTexists;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTvisitor;
import com.paracamplus.ilp4.interfaces.IASTprogram;
import com.paracamplus.ilp4.interpreter.interfaces.IClassEnvironment;

public class Interpreter extends com.paracamplus.ilp4.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> 
{
    
	public Interpreter (IGlobalVariableEnvironment globalVariableEnvironment,
            IOperatorEnvironment operatorEnvironment,
            IClassEnvironment classEnvironment) {
		super(globalVariableEnvironment, operatorEnvironment,classEnvironment);
	}
	
	private List<String> gvariables;

    protected IClassEnvironment classEnvironment;
    
    
    public IClassEnvironment getClassEnvironment () {
        return classEnvironment;
    }
    
     @Override
    public Object visit(com.paracamplus.ilp1.interfaces.IASTprogram iast, ILexicalEnvironment lexenv) throws EvaluationException {
    	 ASTGlobalVariableCollector pass = new ASTGlobalVariableCollector();
    	 this.gvariables = pass.visit((IASTprogram)iast);

    	return visit((IASTprogram)iast, lexenv);
    }

	@Override
	public Object visit(IASTexists iast, ILexicalEnvironment data) throws EvaluationException {
		String varName = iast.getVarName();
		if (data.isPresent(new ASTvariable(varName)) || gvariables.contains(varName) || globalVariableEnvironment.getGlobalVariableValue(varName) != null )
			return Boolean.TRUE;
		
		return Boolean.FALSE;
	}

   
}
