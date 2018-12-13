package com.paracamplus.ilp3.ilp3tme7.interpreter;

import java.util.List;
import java.util.concurrent.Semaphore;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.Invocable;


public class CoroutineInstance extends Thread {
	
	private List<Object> args;
	private Invocable func;
	private Interpreter interpreteur;
	private Semaphore sem_resume = new Semaphore(0);
	private Semaphore sem_yield = new Semaphore(0);
	private boolean finished = false;
	
	public CoroutineInstance(
			Invocable f,
			List<Object> a,
			Interpreter i
			) {
		func = f;
		args  = a;
		interpreteur = i;
		
	}
	
	public void run() {
	
		try {
			sem_resume.acquire();
			func.apply(interpreteur, args.toArray());
			finished =true;
		} catch (EvaluationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InterruptedException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		sem_yield.release();
		return;
	}
	
	public void sem_release () {
		sem_resume.release();
		try {
			if (!finished) { 
			sem_yield.acquire();}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void sem_yield() {

		try {
			sem_yield.release();
			sem_resume.acquire();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
