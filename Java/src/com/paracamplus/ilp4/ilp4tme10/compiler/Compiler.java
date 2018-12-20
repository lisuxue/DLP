/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.compiler;

import com.paracamplus.ilp1.compiler.CompilationException;
import com.paracamplus.ilp1.compiler.ast.ASTCvariable;
import com.paracamplus.ilp1.compiler.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.compiler.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTexists;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTvisitor;


public class Compiler extends com.paracamplus.ilp4.compiler.Compiler
implements IASTvisitor<Void, Compiler.Context, CompilationException> {
  
    
	public Compiler(IOperatorEnvironment ioe, IGlobalVariableEnvironment igve) {
			super(ioe, igve);
	}

	@Override
	public Void visit(IASTexists iast, Context data) throws CompilationException {
		String name = iast.getVarName();
		if(globalVariableEnvironment.contains(new ASTCvariable(name)))
		{
			emit(data.destination.compile());
			emit("ILP_TRUE");
		}
		
		return null;
	}

}
