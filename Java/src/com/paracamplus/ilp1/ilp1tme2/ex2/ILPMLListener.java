package com.paracamplus.ilp1.ilp1tme2.ex2;

import com.paracamplus.ilp1.interfaces.IASTfactory;

import antlr4.ILPMLgrammar1Parser.ConstFalseContext;
import antlr4.ILPMLgrammar1Parser.ConstFloatContext;
import antlr4.ILPMLgrammar1Parser.ConstIntegerContext;
import antlr4.ILPMLgrammar1Parser.ConstStringContext;
import antlr4.ILPMLgrammar1Parser.ConstTrueContext;

public class ILPMLListener extends com.paracamplus.ilp1.parser.ilpml.ILPMLListener{

	public int cpt;
	
	
	public ILPMLListener(IASTfactory factory) {
		super(factory);
		cpt=0;
	}
	
	@Override 
	public void exitConstFloat(ConstFloatContext ctx) { 
		super.exitConstFloat(ctx);
		cpt++;
		
	}

	@Override 
	public void	exitConstInteger(ConstIntegerContext ctx) { 
		super.exitConstInteger(ctx);
		cpt++;
		
	}
	
	@Override 
	public void exitConstTrue(ConstTrueContext ctx) {
		super.exitConstTrue(ctx);
		cpt++;
	}

	@Override 
	public void exitConstString(ConstStringContext ctx) { 
		super.exitConstString(ctx);
		cpt++;
	}

	@Override 
	public void exitConstFalse(ConstFalseContext ctx) {
		super.exitConstFalse(ctx);
		cpt++;
	}

	
}
