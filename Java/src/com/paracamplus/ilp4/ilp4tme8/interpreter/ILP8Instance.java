/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.interpreter;

import java.util.HashMap;
import java.util.Map;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp4.interpreter.ILP9Instance;
import com.paracamplus.ilp4.interpreter.interfaces.IClass;
import com.paracamplus.ilp4.interpreter.interfaces.IInstance;

public class ILP8Instance extends ILP9Instance implements IInstance {
    
    private Map<String, Object> properties = new HashMap<String,Object>();
	
	public ILP8Instance (IClass clazz, Object[] fields) 
            throws EvaluationException {
        super(clazz,fields);   
    }
	
    public boolean isProperty(String property) {
    	return properties.containsKey(property);
    }
    
    public Object readProperty(String property) throws EvaluationException{
    	try {
    		return properties.get(property);
    	} catch(NullPointerException e) {
    		throw new EvaluationException("La proprieté n'existe pas");
    	}
    }
    
    public Object writeProperty(String property, Object newValue) {
    	Object oldValue = properties.put(property, newValue);
    	return oldValue == null ? Boolean.FALSE : oldValue;
    }
    
    
    
   
}
