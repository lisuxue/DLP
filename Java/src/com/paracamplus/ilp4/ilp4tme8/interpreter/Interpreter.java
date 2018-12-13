/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.interpreter;

import java.util.List;
import java.util.Vector;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASThasProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTreadProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTvisitor;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTwriteProperty;
import com.paracamplus.ilp4.interfaces.IASTinstantiation;
import com.paracamplus.ilp4.interpreter.interfaces.IClass;
import com.paracamplus.ilp4.interpreter.interfaces.IClassEnvironment;

public class Interpreter extends com.paracamplus.ilp4.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> 
{
    
	public Interpreter (IGlobalVariableEnvironment globalVariableEnvironment,
            IOperatorEnvironment operatorEnvironment,
            IClassEnvironment classEnvironment ) {
		super(globalVariableEnvironment, operatorEnvironment, classEnvironment);
	}


    @Override
	public Object visit(IASTinstantiation iast, ILexicalEnvironment lexenv) 
            throws EvaluationException {
        IClass clazz = getClassEnvironment().getILP9Class(iast.getClassName());
        List<Object> args = new Vector<Object>();
        for ( IASTexpression arg : iast.getArguments() ) {
            Object value = arg.accept(this, lexenv);
            args.add(value);
        }
        return new ILP8Instance(clazz, args.toArray());
    }

	@Override
	public Object visit(IASTreadProperty iast, ILexicalEnvironment lexenv) throws EvaluationException {
		 Object prop = iast.getProperty().accept(this, lexenv);
		 if (!(prop instanceof String)) {
			 throw new EvaluationException("PAS UN STRING");
		 }
		 String propName = (String)prop;
		 Object target = iast.getTarget().accept(this, lexenv);
	     if ( target instanceof ILP8Instance ) {
	    	 return ((ILP8Instance) target).readProperty(propName);
	     } else {
	    	 String msg = "Not an ILP8 instance " + target;
	         throw new EvaluationException(msg);
	     }
	}

	@Override
	public Object visit(IASTwriteProperty iast, ILexicalEnvironment lexenv) throws EvaluationException {
		Object prop = iast.getProperty().accept(this, lexenv);
		 if (!(prop instanceof String)) {
			 throw new EvaluationException("PAS UN STRING");
		 }
		 String propName = (String)prop;
		 Object target = iast.getTarget().accept(this, lexenv);
	     if ( target instanceof ILP8Instance ) {
	    	 Object val = iast.getValue().accept(this, lexenv);
	    	 return ((ILP8Instance) target).writeProperty(propName,val);
	     } else {
	    	 String msg = "Not an ILP8 instance " + target;
	         throw new EvaluationException(msg);
	     }
	}

	@Override
	public Object visit(IASThasProperty iast, ILexicalEnvironment lexenv) throws EvaluationException {
		 Object prop = iast.getProperty().accept(this, lexenv);
		 if (!(prop instanceof String)) {
			 throw new EvaluationException("PAS UN STRING");
		 }
		 String propName = (String)prop;
		 Object target = iast.getTarget().accept(this, lexenv);
	     if ( target instanceof ILP8Instance ) {
	    	 return ((ILP8Instance) target).isProperty(propName);
	     } else {
	    	 String msg = "Not an ILP8 instance " + target;
	         throw new EvaluationException(msg);
	     }
	}
   
}
