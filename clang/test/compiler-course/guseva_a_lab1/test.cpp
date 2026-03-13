// RUN: %clang_cc1 -load %llvmshlibdir/OverrideVisitor_Guseva_Alena_FIIT2_ClangAST%pluginext -plugin OverrideCheckPlugin %s -fsyntax-only 2>&1 | FileCheck %s

class Base1 {
public:
    virtual void foo();
};

class Derived1 : public Base1 {
public:
// CHECK: warning: virtual method is not marked 'override'
    void foo(); 
};

class Base2 {
public:
    virtual void foo();
};

class Derived2 : public Base2 {
public:
// CHECK-NOT: warning: virtual method is not marked 'override'
    void foo() override;
};
