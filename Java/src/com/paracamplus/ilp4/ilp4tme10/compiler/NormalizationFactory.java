/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.compiler;


import com.paracamplus.ilp4.ilp4tme10.ast.ASTexists;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTexists;

public class NormalizationFactory
extends com.paracamplus.ilp4.compiler.normalizer.NormalizationFactory
implements INormalizationFactory {
    
    @Override
	public IASTexists newExists(String varName) {
        return new ASTexists(varName);
    }
}
