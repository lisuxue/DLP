/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.compiler;

import com.paracamplus.ilp1.compiler.AssignDestination;
import com.paracamplus.ilp1.compiler.CompilationException;
import com.paracamplus.ilp1.compiler.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.compiler.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interfaces.Inamed;
import com.paracamplus.ilp4.compiler.interfaces.IASTCclassDefinition;
import com.paracamplus.ilp4.compiler.interfaces.IASTCfieldRead;
import com.paracamplus.ilp4.compiler.interfaces.IASTCfieldWrite;
import com.paracamplus.ilp4.compiler.interfaces.IASTCvisitor;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASThasProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTreadProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTvisitor;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTwriteProperty;
import com.paracamplus.ilp4.interfaces.IASTfieldRead;
import com.paracamplus.ilp4.interfaces.IASTfieldWrite;
import com.paracamplus.ilp4.interfaces.IASTself;
import com.paracamplus.ilp4.interfaces.IASTsend;
import com.paracamplus.ilp4.interfaces.IASTsuper;


public class Compiler extends com.paracamplus.ilp4.compiler.Compiler
implements IASTvisitor<Void, Compiler.Context, CompilationException> {
  
    
	public Compiler(IOperatorEnvironment ioe, IGlobalVariableEnvironment igve) {
			super(ioe, igve);
		}

 
 
    @Override
	public Void visit(IASTfieldRead iast, Context context)
            throws CompilationException {
        if ( iast instanceof IASTCfieldRead ) {
            return visit((IASTCfieldRead)iast, context);
        } else {
            String msg = "Should not occur";
            throw new CompilationException(msg);
        }
    }
 
    @Override
	public Void visit(IASTCfieldRead iast, Context context)
            throws CompilationException {
        emit("{ \n");
        IASTvariable tmpInstance = context.newTemporaryVariable();
        emit("  ILP_Object " + tmpInstance.getMangledName() + "; \n");
        Context c = context.redirect(new AssignDestination(tmpInstance));
        iast.getTarget().accept(this, c);
        
        IASTCclassDefinition clazz = iast.getDefiningClass();
        emit("if ( ILP_IsA(");
        emit(tmpInstance.getMangledName());
        emit(", ");
        emit(clazz.getMangledName());
        emit(" ) ) {\n");
        emit(context.destination.compile());
        emit(tmpInstance.getMangledName());
        emit("->_content.asInstance.field[");
        emit(clazz.getFieldOffset(iast.getFieldName()));
        emit("];\n} else {\n");
        emit(context.destination.compile());
        emit(" ILP_UnknownFieldError(\"");
        emit(Inamed.computeMangledName(iast.getFieldName()));
        emit("\", ");
        emit(tmpInstance.getMangledName());
        emit(");\n}\n}\n");
        return null;
    }
    
    /***
     * 
     * 
     * 
     * 
     */
    @Override
   	public Void visit(IASTreadProperty iast, Context context)
               throws CompilationException {
           emit("{ \n");
           IASTvariable tmpInstance = context.newTemporaryVariable();
           emit("  ILP_Object " + tmpInstance.getMangledName() + "; \n");
           Context c = context.redirect(new AssignDestination(tmpInstance));
           iast.getTarget().accept(this, c);
           
           IASTCclassDefinition clazz = iast.getDefiningClass();
           emit("if ( ILP_IsA(");
           emit(tmpInstance.getMangledName());
           emit(", ");
           emit(clazz.getMangledName());
           emit(" ) ) {\n");
           emit(context.destination.compile());
           emit(tmpInstance.getMangledName());
           emit("->_content.asInstance.field[");
           emit(clazz.getFieldOffset(iast.getFieldName()));
           emit("];\n} else {\n");
           emit(context.destination.compile());
           emit(" ILP_UnknownFieldError(\"");
           emit(Inamed.computeMangledName(iast.getFieldName()));
           emit("\", ");
           emit(tmpInstance.getMangledName());
           emit(");\n}\n}\n");
           return null;
       }
    
    @Override
	public Void visit(IASTfieldWrite iast, Context context)
            throws CompilationException {
        if ( iast instanceof IASTCfieldWrite ) {
            return visit((IASTCfieldWrite)iast, context);
        } else {
            String msg = "Should not occur";
            throw new CompilationException(msg);
        }
    }
    
    @Override
	public Void visit(IASTCfieldWrite iast, Context context)
            throws CompilationException {
        emit("{ \n");
        IASTvariable tmpInstance = context.newTemporaryVariable();
        emit("  ILP_Object " + tmpInstance.getMangledName() + "; \n");
        Context c = context.redirect(new AssignDestination(tmpInstance));

        IASTvariable tmpValue = context.newTemporaryVariable();
        emit("  ILP_Object " + tmpValue.getMangledName() + "; \n");
        Context cv = context.redirect(new AssignDestination(tmpValue));
        
        iast.getTarget().accept(this, c);
        iast.getValue().accept(this, cv);
        
        IASTCclassDefinition clazz = iast.getDefiningClass();
        emit("if ( ILP_IsA(");
        emit(tmpInstance.getMangledName());
        emit(", ");
        emit(clazz.getMangledName());
        emit(" ) ) {\n");
        emit(context.destination.compile());
        emit(tmpInstance.getMangledName());
        emit("->_content.asInstance.field[");
        emit(clazz.getFieldOffset(iast.getFieldName()));
        emit("] = ");
        emit(tmpValue.getMangledName());
        emit(";\n} else {\n");
        emit(context.destination.compile());
        emit(" ILP_UnknownFieldError(\"");
        emit(Inamed.computeMangledName(iast.getFieldName()));
        emit("\", ");
        emit(tmpInstance.getMangledName());
        emit(");\n}\n}\n");
        return null;
    }

    
    
    
    
    
    
    
    @Override
	public Void visit(IASTsend iast, Context context)
            throws CompilationException {
        emit("{ \n");
        IASTvariable tmpMethod = context.newTemporaryVariable();
        emit("  ILP_general_function " + tmpMethod.getMangledName() + "; \n");
        IASTvariable tmpReceiver = context.newTemporaryVariable();
        emit("  ILP_Object " + tmpReceiver.getMangledName() + "; \n");
        Context c = context.redirect(new AssignDestination(tmpReceiver));

        IASTexpression[] arguments = iast.getArguments();
        IASTvariable[] tmps = new IASTvariable[arguments.length];
        for ( int i=0 ; i<arguments.length ; i++ ) {
            IASTvariable tmp = context.newTemporaryVariable();
            emit("  ILP_Object " + tmp.getMangledName() + "; \n");
            tmps[i] = tmp;
        }
        
        iast.getReceiver().accept(this, c);
        for ( int i=0 ; i<arguments.length ; i++ ) {
            IASTexpression expression = arguments[i];
            IASTvariable tmp = tmps[i];
            Context c2 = context.redirect(new AssignDestination(tmp));
            expression.accept(this, c2);
        }

        emit(tmpMethod.getMangledName());
        emit(" = ILP_find_method(");
        emit(tmpReceiver.getMangledName());
        emit(", &ILP_object_");
        emit(Inamed.computeMangledName(iast.getMethodName()));
        emit("_method, ");
        emit(1 + arguments.length);
        emit(");\n");

        emit(context.destination.compile());
        emit(tmpMethod.getName());
        emit("(NULL, ");
        emit(tmpReceiver.getMangledName());
        for ( int i = 0 ; i<arguments.length ; i++ ) {
          emit(", ");
          emit(tmps[i].getMangledName());
        }
        emit(");\n}\n");
        return null;
    }
    
    @Override
	public Void visit(IASTself iast, Context context)
            throws CompilationException {
        // Totally removed now, see Normalizer.visit(IASTself,...)
        throw new RuntimeException("NYI");
    }
        
    @Override
	public Void visit(IASTsuper iast, Context context)
            throws CompilationException {
        emit(context.destination.compile());
        emit("ILP_FindAndCallSuperMethod(); \n");
        return null;
    }



	@Override
	public Void visit(IASTwriteProperty iast, Context data) throws CompilationException {
		// TODO Auto-generated method stub
		return null;
	}



	@Override
	public Void visit(IASThasProperty iast, Context data) throws CompilationException {
		// TODO Auto-generated method stub
		return null;
	}
}
