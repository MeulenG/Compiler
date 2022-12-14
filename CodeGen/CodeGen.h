#ifndef CODEGEN_H
#define CODEGEN_H
#include "../Ast/Ast.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

using namespace std;


class CodeGen
{
public:
	CodeGen();
	~CodeGen();
	unique_ptr<llvm::LLVMContext> TheContext;
	unique_ptr<llvm::Module> TheModule;
	unique_ptr<llvm::IRBuilder<>> Builder;
	
	

private:

};

CodeGen::CodeGen()
{
	
}

CodeGen::~CodeGen()
{
	
}



#endif // !CODEGEN_H
