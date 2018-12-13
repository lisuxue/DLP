package com.paracamplus.ilp2.ilp2tme6.interpreter;

import java.util.HashMap;
import java.util.Map;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interfaces.IASTblock.IASTbinding;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp2.interfaces.IASTfactory;
import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;
import com.paracamplus.ilp2.interfaces.IASTprogram;

public class InlineTransform extends CopyTransform<Void>{

	private Map<String,IASTfunctionDefinition> mapfun = new HashMap<String,IASTfunctionDefinition>();
	
	public InlineTransform(IASTfactory factory) {
		super(factory);
		// TODO Auto-generated constructor stub
	}
	
	public IASTprogram visit(IASTprogram iast, ILexicalEnvironment lexenv) 
            throws EvaluationException {
        for ( IASTfunctionDefinition fd : iast.getFunctionDefinitions() ) {
        	IASTvariable nom = factory.newVariable(fd.getName());
        	IASTvariable[] args = fd.getVariables().clone();
        	IASTexpression body = fd.getBody().accept(this, null);   	
        	mapfun.put(fd.getName(), factory.newFunctionDefinition(nom, args, body));
        }
        
        return factory.newProgram(iast.getFunctionDefinitions(), iast.getBody().accept(this, null));
    }

	@Override
	public IASTexpression visit(IASTinvocation iast, Void data) throws EvaluationException {
	
		if ( ! (iast.getFunction() instanceof IASTvariable)) 
			return factory.newInvocation(iast.getFunction(), iast.getArguments());
	
		IASTvariable varFun = (IASTvariable)iast.getFunction();
		IASTfunctionDefinition fd = mapfun.get(varFun.getName());
		if (fd==null) throw new EvaluationException("not defined function");
		
		IASTbinding[] bindings = new IASTbinding[iast.getArguments().length];
		
        for ( int i = 0; i < iast.getArguments().length; i++ ) {
        	bindings[i]=factory.newBinding(fd.getVariables()[i], iast.getArguments()[i].accept(this, data));
        }
		return factory.newBlock(bindings, fd.getBody());
	}
	

}
