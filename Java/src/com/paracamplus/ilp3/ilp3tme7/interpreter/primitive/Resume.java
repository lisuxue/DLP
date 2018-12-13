/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp3.ilp3tme7.interpreter.primitive;


import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.UnaryPrimitive;
import com.paracamplus.ilp3.ilp3tme7.interpreter.CoroutineInstance;

public class Resume extends UnaryPrimitive { 
    
    public Resume() {
        super("resume");
    }
        
    @Override
	public Object apply (Object value) throws EvaluationException {
    	if( value instanceof CoroutineInstance)
    	{
    		CoroutineInstance coi = (CoroutineInstance) value;
    		coi.sem_release();
    		return Boolean.FALSE;
    	}
        return Boolean.TRUE;
    }

}
