package com.paracamplus.ilp2.ilp2tme5bis.interpreter.exception;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;


@SuppressWarnings("serial")
public class BreakException extends EvaluationException{

	public BreakException(String msg) {
		super(msg);
	}
	

}
