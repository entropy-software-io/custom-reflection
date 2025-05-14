// Copyright (c) Entropy Software LLC
// This file is licensed under the MIT License.
// See the LICENSE file in the project root for more information.

#include "Entropy/Reflection.h"
#include <iostream>

int main(int argc, char* argv[])
{
    using namespace Entropy;

    const TypeInfo* typeInfo = ReflectTypeAndGetTypeInfo<MyNamespace::MyCustomType>();

    bool isMyType = typeInfo->Get<MyNamespace::CustomTypeInfo>().IsMyCustomType();
    std::cout << "Is My Type: " << (isMyType ? "True" : "False") << std::endl;
}
