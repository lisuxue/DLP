package com.paracamplus.ilp2.ilp2tme5bis.interpreter.exception;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;


@SuppressWarnings("serial")
public class ContinueException extends EvaluationException {

	public ContinueException(String msg) {
		super(msg);
	}

}
