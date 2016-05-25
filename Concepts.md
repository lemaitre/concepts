# Concepts implemented in `concepts.h`

## Basic types
### Single tests
- `Void<T>`: T is `void` or any cv-qualified variant of `void`
- `Null<T>`: T is `std::nullptr_t` or any cv-qualified variant of `std::nullptr_t`
- `Integral<T>`: T represents integers (all variants of `int`, internally: `std::is_integral<T>`)
- `FloatingPoint<T>`: T represents floating point numbers (`float` or `double`, internally: `std::is_floating_point<T>`)
- `Array<T>`: T is a C array (like `int[]` or `char[32]`)
- `Enum<T>`: T is an `enum`
- `Union<T>`: T is an `union`
- `Class<T>`: T is a `class`
- `Function<T>`: T is a function: not a function pointer nor a callable object nor a lambda
- `Pointer<T>: T is a pointer (like `int*`)
- `MemberObjectPointer<T>`: T is a member pointer to an attribute
- `MemberFunctionPointer<T>`: T is a member pointer to a member function

### Compound tests
- `MemberPointer<T`>: T is either a member pointer to an attribute or a member pointer to a member function
- `Unsigned<T>`: T is an unsigned integer type (like `unsigned int` or `unsigned char`)
- `Signed<T>`: T is a signed integer type (like `int` or `long long int`)
- `Fundamental<T>`: T is a fundamental type (all variants of `int`, `float`, `double`, `std::nullptr_t` or `void`)
- `Compound<T>`: T is a compound type, ie: not fundamental
- `Scalar<T>`: T is a scalar type: either a variant of `int`, `float`, `double`, a pointer, a pointer to member, an enumeration or `std::nullptr_t`
- `Object<T>`: T is an object type: everything that is not a function, a reference of `void`

### Type comparisons
- `Same<T1, T2>`: T1 and T2 are the same type (and not only mutually convertible)
- `Convertible<T1, T2>`: T1 is convertible into T2
- `Compatible<T1, T2>`: T1 and T2 are mutally convertible, ie: Convertible<T1, T2> and Convertible<T2, T1>
- `Common<Args...>`: It exists a common type to every type of `Args...`. This type can be retrivied with `CommonType<Args...>` (ex: `CommonType<int, float>` -> `float`)

## Type qualifiers
- `Const<T>`: T is const (like `const int`)
- `Volatile<T>`: T is volatile (like `volatile float`)
- `lValue<T>`: T is a lvalue reference
- `rValue<T>`: T is a rvalue reference
- `Reference<T>`: T is a reference, either rvalue reference or lvalue reference (like `int&` or `float&&`)
- `ConstReference<T>`: T is a const reference, either rvalue reference or lvalue reference (like `const int&` or `const float&&`)

## Custom type information
- `Literal<T>`: T is a literal type: manipulable by `constexpr` expressions
- `Empty<T>`: T contains no attribute
- `POD<T>` or `PODType<T>`: T is a POD (a C like struct: no constructor, no destructor, no `operator=()`)
- `StandardLayout<T>`: T has a standard memory layout: no attribute except for base classes
- `Polymorphic<T>`: T has virtual methods
- `Abstract<T>`: T does not implement every virtual functions of its parents
- `Derived<D, B>`: D derives/inherits from B: B is the base of D`

### Constructors
- `Constructible<T, Args...>`: T is constructible with `Args...` arguments
- `TriviallyConstructible<T, Args...>`: T is trivially constructible with `Args...` arguments
- `NothrowConstructible<T, Args...>`: T is constructible with `Args...` arguments and never throws exception
- `CopyConstructible<T>`: T is copy constructible
- `TriviallyCopyConstructible<T>`: T is trivially copy constructible (equivalent to `memcopy`)
- `NothrowCopyConstructible<T>`: T is copy constructible and never throws exception
- `MoveConstructible<T>`: T is move constructible
- `TriviallyMoveConstructible<T>`: T is trivially move constructible (equivalent to `memcopy`)
- `NothrowMoveConstructible<T>`: T is move constructible and never throws exception

### Assignment
- `Assignable<T, A>`: T is assignable with rhs of type A
- `TriviallyAssignable<T, A>`: T is trivially assignable with rhs of type A
- `NothrowAssignable<T, A>`: T is assignable with rhs of type A and never throws exception
- `CopyAssignable<T>`: T is copy assignable
- `TriviallyCopyAssignable<T>`: T is trivially copy assignable (equivalent to `memcopy`)
- `NothrowCopyAssignable<T>`: T is copy assignable and never throws exception
- `MoveAssignable<T>`: T is move assignable
- `TriviallyMoveAssignable<T>`: T is trivially move assignable (equivalent to `memcopy`)
- `NothrowMoveAssignable<T>`: T is move assignable and never throws exception

### Destructors
- `Destructible<T>`: T is destructible
- `TriviallyDestructible<T>`: T is trivially destructible (equivalent to noop)
- `NothrowDestructible<T>`: T is destructible and never throws exception
- `VirtualDestructor<T>`: T has a virtual destructor

### Language semantics
- `Trivial<T>`: T is a trivial type: trivially constructible and trivially copyable
- `Copyable<T>`: T is copyable (copy constructor + copy assignment)
- `TriviallyCopyable<T>`: T is a trivially copyable (copy equivalent to `memcopy`)
- `NothrowCopyable<T>`: T is a copyable and copy never throws exception
- `Moveable<T>`: T is moveable (move constructor + move assignment)
- `TriviallyMoveable<T>`: T is a trivially moveable (move equivalent to `memcopy`)
- `NothrowMoveable<T>`: T is a moveable and move never throws exception
- `Swappable<T>`: two elements of T can be swapped
- `Swappable<T1, T2>`: T1 element can be swapped with T2 element
- `NothrowSwappable<T>`: two elements of T can be swapped without exception

### Custom semantics
#### Callable
- `Callable<T, Args...>`: T elements can be called with `Args...` arguments (like a regular function)
- `FunctionObject<T, Args...>`: T is callable with `Args...` and is an object
- `Predicate<T, Args...>`: T is callable with `Args...` and result is a boolean
- `UnaryPredicate<T, A1>`: T is a predicate with one argument
- `BinaryPredicate<T, A1, A2>`: T is a predicate with one argument
- `Operator<T, Args...>`: T is callable with `Args...` and result is not `void`
- `UnaryOperator<T, A1>`: T is a predicate with one argument
- `BinaryOperator<T, A1, A2>`: T is a predicate with one argument

#### Comparisons
- `EqualityComparable<T>`: two elements of T can be compared with `==` operator
- `EqualityComparable<T1, T2>`: a T1 element and a T2 element can be compared with `==` operator
- `Comparable<T>`: two elements of T can be compared with `==` or `!=` operators
- `Comparable<T1, T2>`: a T1 element and a T2 element can be compared with `==` or `!=` operators
- `LessThanComparable<T>`: two elements of T can be compared with `<` operator
- `LessThanComparable<T1, T2>`: a T1 element and a T2 element can be compared with `<` operator
- `WeaklyOrdered<T>`: two elements of T can be compared with `<`, `<=`, `>` or `>=`  operators
- `WeaklyOrdered<T1, T2>`: a T1 element and a T2 element can be compared with `<`, `<=`, `>` or `>=`  operators
- `Ordered<T>`: T is both WeaklyOrdered and Comparable
- `Ordered<T1, T2>`: T1 and T2 are both WeaklyOrdered and Comparable

#### Arithmetic
- `ArithmeticAdd<T>`: T implements `+`, `-`, `+=` and `-=` operators
- `ArithmeticAdd<T1, T2>`: `+`, `-`, `+=` and `-=` operators are available with (T1, T1), (T2, T2), (T1, T2), (T2, T1) types
- `CompatibleArithmeticAdd<T1, T2>`: T1 and T2 implements ArithmeticAdd. T1+T2 and T1+=T2 are implemented but not T2+T1 nor T2+=T1
- `ArithmeticMul<T>`: T implements `*`, `/`, `*=` and `/=` operators
- `ArithmeticMul<T1, T2>`: `*`, `/`, `*=` and `/=` operators are available with (T1, T1), (T2, T2), (T1, T2), (T2, T1) types
- `CompatibleArithmeticMul<T1, T2>`: T1 and T2 implements ArithmeticAdd. T1*T2 and T1*=T2 are implemented but not T2*T1 nor T2*=T1
- `Arithmetic<T>`: T is ArithmeticAdd and ArithmeticMul
- `CompatibleArithmetic<T>`: T is CompatibleArithmeticAdd and CompatibleArithmeticMul
- `Arithmetic<T1, T2>`: T1 and T2 are ArithmeticAdd and ArithmeticMul
- `CompatibleArithmetic<T1, T2>`: T1 and T2 are CompatibleArithmeticAdd and CompatibleArithmeticMul

#### Integer arithmetic
- `PreIncrementable<T>`: a t element of type T can be preincremented: ++t
- `PostIncrementable<T>`: a t element of type T can be postincremented: t++
- `Incrementable<T>`: T is both PreIncrementable and PostIncrementable
- `PreDecrementable<T>`: a t element of type T can be predecremented: ++t
- `PostDecrementable<T>`: a t element of type T can be postdecremented: t++
- `Decrementable<T>`: T is both PreDecrementable and PostDecrementable
- `Bitmask<T>`: T implements `|`, `&`, `^`, `|=`, `&=` and `^=` operators
- `Bitmask<T1, T2>`: T1 and T2 implement `|`, `&`, `^`, `|=`, `&=` and `^=` operators
- `ShiftableBitmask<T>`: T implements `|`, `&`, `^`, `|=`, `&=`, `^=`, `<<`, `>>`, `<<=` and `>>=` operators

#### Iterators
- `Dereferenceable<T>`: T implements `*` operator and this operator returns a reference
- `ValueSwappable<T>`: T is Dereferenceable and the referenced type is Swappable
- `ValueSwappable<T1, T2>`: T1 and T2 are Dereferenceable and the referenced types are Swappable
- `NothrowValueSwappable<T>`: T is Dereferenceable and the referenced type is NothrowSwappable
- `NothrowValueSwappable<T1, T2>`: T1 and T2 are Dereferenceable and the referenced types are NothrowSwappable
- `Iterator<T>`: T is an object (constructible, copyable, destructible and sappable) that is dereferenceable and preincrementable
- `MutableIterator<T>`: the value referenced by the iterator T is assignable
- `ConstIterator<T>`: the value referenced by the iterator T is not assignable
- `InputIterator<T>`: T is an Iterator that is also incrementable
- `MutableInputIterator<T>`: the value referenced by the InputIterator T is assignable
- `ConstInputIterator<T>`: the value referenced by the InputIterator T is not assignable
- `ForwardIterator<T>`: T is an InputIterator that is also comparable
- `MutableForwardIterator<T>`: the value referenced by the ForwardIterator T is assignable
- `ConstForwardIterator<T>`: the value referenced by the ForwardIterator T is not assignable
- `BidirectionnalIterator<T>`: T is a ForwardIterator that is also Decrementable
- `MutableBidirectionnalIterator<T>`: the value referenced by the BidirectionnalIterator T is assignable
- `ConstBidirectionnalIterator<T>`: the value referenced by the BidirectionnalIterator T is not assignable
- `RandomAccessIterator<T>`: T is a BidirectionnalIterator that implements `+`, `-` and `[]` and is Ordered
- `MutableRandomAccessIterator<T>`: the value referenced by the RandomAccessIterator T is assignable
- `ConstRandomAccessIterator<T>`: the value referenced by the RandomAccessIterator T is not assignable

#### Containers
- `Container<T>`: T is an object (default constructible, copyable, destructible, comparable, swappable) that implements `.size()`, `.empty()`, `.begin()`, `.cbegin()`, `.end()` and `.cend()`
- `ReversibleContainer<T>`: T is a Container that implements `.rbegin()`, `.crbegin()`, `.rend()` and `.crend()`

#### Others
- `Boolean<T>`: T is useable in boolean context (conditions)
- `Allocator<T>`: T is an allocator
- `Hash<T>`: T is a callable that can be used as a hash function
