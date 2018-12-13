/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp3.ilp3tme7.interpreter.primitive;


import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.Primitive;
import com.paracamplus.ilp3.ilp3tme7.interpreter.CoroutineInstance;

public class Yield extends Primitive { 
    
    public Yield() {
        super("yield");
    }
        
    @Override
	public Object apply () throws EvaluationException {
    	CoroutineInstance coi = (CoroutineInstance) Thread.currentThread(); 
    	coi.sem_yield();
        return  null;  
    }

	@Override
	public int getArity() {
		return 0;
	}
}
