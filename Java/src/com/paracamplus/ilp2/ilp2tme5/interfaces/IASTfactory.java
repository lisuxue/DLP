/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme5.interfaces;


public interface IASTfactory extends com.paracamplus.ilp2.interfaces.IASTfactory {

    IASTcontinue newContinue();
    IASTbreak newBreak();
}
