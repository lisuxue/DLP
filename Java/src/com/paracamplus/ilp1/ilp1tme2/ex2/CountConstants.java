package com.paracamplus.ilp1.ilp1tme2.ex2;


import com.paracamplus.ilp1.interfaces.IASTalternative;
import com.paracamplus.ilp1.interfaces.IASTbinaryOperation;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTboolean;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTfloat;
import com.paracamplus.ilp1.interfaces.IASTinteger;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp1.interfaces.IASTprogram;
import com.paracamplus.ilp1.interfaces.IASTsequence;
import com.paracamplus.ilp1.interfaces.IASTstring;
import com.paracamplus.ilp1.interfaces.IASTunaryOperation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interfaces.IASTvisitor;
import com.paracamplus.ilp1.interfaces.IASTblock.IASTbinding;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;


/*
 * Cette Classe contient les méthodes visit de la même façon que la classe Interpreter.java 
 * Elle implémente et n'hérite pas car on doit redéfinir le conportement à adopter 
 * pour compter les constantes présents dans le programme, completement différent.
 * 
 * 
 * */
public class CountConstants implements IASTvisitor<Integer, Object, EvaluationException>{
	
	protected int cpt=0;
	
	public CountConstants() {
	}
	
	
	
    public Integer visit(IASTprogram iast, Object data) throws EvaluationException {
        try {
            return iast.getBody().accept(this, cpt);
        } catch (Exception exc) {
            return -10;
        }
    }

	@Override
	public Integer visit(IASTalternative iast, Object data) throws EvaluationException {
		int condition = iast.getCondition().accept(this, data);
		int consequence = iast.getConsequence().accept(this, data);
		int alternant = 0;
		if ( iast.isTernary() ) {
           alternant = iast.getAlternant().accept(this, data); 
		}
		return condition + consequence + alternant ;
	}

	@Override
	public Integer visit(IASTbinaryOperation iast, Object data) throws EvaluationException {
		int leftOperand = iast.getLeftOperand().accept(this, data);
        int rightOperand = iast.getRightOperand().accept(this, data);
		return leftOperand+rightOperand;
	}

	@Override
	public Integer visit(IASTblock iast, Object data) throws EvaluationException {
		int initialisation=0;
		int body;
		for ( IASTbinding binding : iast.getBindings() ) {
            initialisation = binding.getInitialisation().accept(this, data);
		}
		body = iast.getBody().accept(this, data);
		return initialisation + body;
	}

	@Override
	public Integer visit(IASTboolean iast, Object data) throws EvaluationException {
		return 1;
	}

	@Override
	public Integer visit(IASTfloat iast, Object data) throws EvaluationException {
		return 1;
	}

	@Override
	public Integer visit(IASTinteger iast, Object data) throws EvaluationException {
		return 1;
	}

	@Override
	public Integer visit(IASTinvocation iast, Object data) throws EvaluationException {
		int function = iast.getFunction().accept(this, data);
		int arguments=0;
        for ( IASTexpression arg : iast.getArguments() ) {
            arguments += arg.accept(this, data);
        }
        return function + arguments;
        
	}

	@Override
	public Integer visit(IASTsequence iast, Object data) throws EvaluationException {
		IASTexpression[] expressions = iast.getExpressions();
        int cte=0;
        for ( IASTexpression e : expressions ) {
            cte += e.accept(this, data);
        }
        return cte;
	}

	@Override
	public Integer visit(IASTstring iast, Object data) throws EvaluationException {
		return 1;
	}

	@Override
	public Integer visit(IASTunaryOperation iast, Object data) throws EvaluationException {
		return iast.getOperand().accept(this, data);
	}

	@Override
	public Integer visit(IASTvariable iast, Object data) throws EvaluationException {
		return 0;
	}

}
