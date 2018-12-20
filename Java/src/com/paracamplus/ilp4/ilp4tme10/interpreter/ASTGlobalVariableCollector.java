/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.interpreter;

import java.util.ArrayList;
import java.util.List;

import com.paracamplus.ilp2.interfaces.IASTassignment;
import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;
import com.paracamplus.ilp2.interfaces.IASTloop;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTvisitor;//modifier
import com.paracamplus.ilp4.interfaces.IASTfieldRead;
import com.paracamplus.ilp4.interfaces.IASTfieldWrite;
import com.paracamplus.ilp4.interfaces.IASTinstantiation;
import com.paracamplus.ilp4.interfaces.IASTself;
import com.paracamplus.ilp4.interfaces.IASTsend;
import com.paracamplus.ilp4.interfaces.IASTsuper;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp2.interfaces.IASTprogram;
import com.paracamplus.ilp3.interfaces.IASTcodefinitions;
import com.paracamplus.ilp3.interfaces.IASTlambda;
import com.paracamplus.ilp3.interfaces.IASTtry;
import com.paracamplus.ilp1.interfaces.IASTsequence;
import com.paracamplus.ilp1.interfaces.IASTstring;
import com.paracamplus.ilp1.interfaces.IASTunaryOperation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interfaces.IASTalternative;
import com.paracamplus.ilp1.interfaces.IASTbinaryOperation;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTboolean;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTfloat;
import com.paracamplus.ilp1.interfaces.IASTinteger;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTexists;

public class ASTGlobalVariableCollector implements IASTvisitor<List<String>, List<String>, EvaluationException> {

	
	public List<String> visit(IASTprogram iast) throws EvaluationException {
		//System.out.println(factory.newProgram(iast.getBody().getClass()));
		List<String> gvar = new ArrayList<String>();
		for( IASTfunctionDefinition f : iast.getFunctionDefinitions())
			gvar.addAll(f.getBody().accept(this, gvar));
		
        return iast.getBody().accept(this, gvar);
    }
	
	public ASTGlobalVariableCollector() {
	}
	
	@Override
	public List<String> visit(IASTassignment iast, List<String> data) throws EvaluationException {
		//// AJOUTER LA VARIABLE
		data.add(iast.getVariable().getName());
		List<String> acc = iast.getExpression().accept(this, data);
		data.addAll(acc);
		return data;
	}

	@Override
	public List<String> visit(IASTloop iast, List<String> data) throws EvaluationException {
		List<String> body = iast.getBody().accept(this, data);
		List<String> cdn = iast.getCondition().accept(this, data);
		data.addAll(body);
		data.addAll(cdn);
		return data;
	}

	@Override
	public List<String> visit(IASTalternative iast, List<String> data) throws EvaluationException {
		
		List<String> cdn = iast.getCondition().accept(this, data);
		List<String> tr = iast.getConsequence().accept(this, data);
		List<String> fl = iast.getAlternant().accept(this, data);
		
		data.addAll(cdn);
		data.addAll(tr);
		data.addAll(fl);
		
		
		return data;
	}

	@Override
	public List<String> visit(IASTbinaryOperation iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTblock iast, List<String> data) throws EvaluationException {		
		data.addAll(iast.getBody().accept(this, data));
		
		return data;
	}

	@Override
	public List<String> visit(IASTboolean iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTfloat iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTinteger iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTinvocation iast, List<String> data) throws EvaluationException {
		
		List<String> func = iast.getFunction().accept(this, data);
		data.addAll(func);
		
		return data;
	}

	@Override
	public List<String> visit(IASTsequence iast, List<String> data) throws EvaluationException {
        for ( IASTexpression expr : iast.getExpressions())
        	data.addAll(expr.accept(this, data));
		return data;
	}

	@Override
	public List<String> visit(IASTstring iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTunaryOperation iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTvariable iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTinstantiation iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTfieldRead iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTself iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTsend iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTsuper iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTfieldWrite iast, List<String> data) throws EvaluationException {
		return data;
	}

	@Override
	public List<String> visit(IASTcodefinitions iast, List<String> data) throws EvaluationException {
		data.addAll(iast.getBody().accept(this, data));
		return data;
	}

	@Override
	public List<String> visit(IASTlambda iast, List<String> data) throws EvaluationException {
		data.addAll(iast.getBody().accept(this, data));
		return data;
	}

	@Override
	public List<String> visit(IASTtry iast, List<String> data) throws EvaluationException {
		data.addAll(iast.getBody().accept(this, data));
		return data;
	}

	@Override
	public List<String> visit(IASTexists iast, List<String> data) throws EvaluationException {
		return data;
	}
    

}