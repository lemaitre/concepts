#ifndef CONCEPTS_H
#define CONCEPTS_H
#include <type_traits>
#include <memory>

namespace Concepts {
  namespace __helper {
    using std::swap;
    template <class A, class B>
    auto __swap(A&& a, B&& b) noexcept(noexcept(swap(std::forward<A>(a), std::forward<B>(b)))) requires requires(A a, B b) {
      swap(std::forward<A>(a), std::forward<B>(b));
    }{
      return swap(std::forward<A>(a), std::forward<B>(b));
    }

    template <class T>
    struct is_const_reference : std::false_type {};
    template <class T>
    struct is_const_reference<const T&> : std::true_type {};
  }
  template <class A>
  concept bool Boolean = requires(A a) {
    (void)(  a ? 1 : 0 );
    (void)( !a ? 1 : 0 );
  };

  // Type traits concepts
  template <class A>
  concept bool Void = std::is_void<A>::value;

  template <class A>
  concept bool Null = std::is_null_pointer<A>::value;

  template <class A>
  concept bool Integral = std::is_integral<A>::value;

  template <class A>
  concept bool FloatingPoint = std::is_floating_point<A>::value;

  template <class A>
  concept bool Array = std::is_array<A>::value;

  template <class A>
  concept bool Enum = std::is_enum<A>::value;

  template <class A>
  concept bool Union = std::is_union<A>::value;

  template <class A>
  concept bool Class = std::is_class<A>::value;

  template <class A>
  concept bool Function = std::is_function<A>::value;

  template <class A>
  concept bool Pointer = std::is_pointer<A>::value;

  template <class A>
  concept bool lValue = std::is_lvalue_reference<A>::value;

  template <class A>
  concept bool rValue = std::is_rvalue_reference<A>::value;

  template <class A>
  concept bool MemberObjectPointer = std::is_member_object_pointer<A>::value;

  template <class A>
  concept bool MemberFunctionPointer = std::is_member_function_pointer<A>::value;

  template <class A>
  concept bool Fundamental = std::is_fundamental<A>::value;

  //template <class A>
  //concept bool Arithmetic = std::is_arithmetic<A>::value;

  template <class A>
  concept bool Scalar = std::is_scalar<A>::value;

  template <class A>
  concept bool Object = std::is_object<A>::value;

  template <class A>
  concept bool Compound = std::is_compound<A>::value;

  template <class A>
  concept bool Reference = std::is_reference<A>::value;

  template <class A>
  concept bool MemberPointer = std::is_member_pointer<A>::value;

  template <class A>
  concept bool Const = std::is_const<A>::value;

  template <class A>
  concept bool Volatile = std::is_volatile<A>::value;

  template <class A>
  concept bool Trivial = std::is_trivial<A>::value;

  template <class A>
  concept bool TriviallyCopyable = std::is_trivially_copyable<A>::value;

  template <class A>
  concept bool StandardLayout = std::is_standard_layout<A>::value;

  template <class A>
  concept bool POD = std::is_pod<A>::value;

  template <class A>
  concept bool PODType = POD<A>;

  template <class A>
  concept bool Literal = std::is_literal_type<A>::value;

  template <class A>
  concept bool Empty = std::is_empty<A>::value;

  template <class A>
  concept bool Polymorphic = std::is_polymorphic<A>::value;

  template <class A>
  concept bool Abstract = std::is_abstract<A>::value;

  template <class A>
  concept bool Signed = std::is_signed<A>::value;

  template <class A>
  concept bool Unsigned = std::is_unsigned<A>::value;

  template <class A, class... Args>
  concept bool Constructible = std::is_constructible<A, Args...>::value;

  template <class A, class... Args>
  concept bool TriviallyConstructible = std::is_trivially_constructible<A, Args...>::value;

  template <class A, class... Args>
  concept bool NothrowConstructible = std::is_nothrow_constructible<A, Args...>::value;

  template <class A>
  concept bool DefaultConstructible = Constructible<A>;

  template <class A>
  concept bool TriviallyDefaultConstructible = TriviallyConstructible<A>;

  template <class A>
  concept bool NothrowDefaultConstructible = NothrowConstructible<A>;

  template <class A>
  concept bool CopyConstructible = Constructible<A, const A&>;

  template <class A>
  concept bool TriviallyCopyConstructible = TriviallyConstructible<A, const A&>;

  template <class A>
  concept bool NothrowCopyConstructible = NothrowConstructible<A, const A&>;

  template <class A>
  concept bool MoveConstructible = Constructible<A, A&&>;

  template <class A>
  concept bool TriviallyMoveConstructible = TriviallyConstructible<A, A&&>;

  template <class A>
  concept bool NothrowMoveConstructible = NothrowConstructible<A, A&&>;

  template <class A, class B>
  concept bool Assignable = std::is_assignable<A, B>::value;

  template <class A, class B>
  concept bool TriviallyAssignable = std::is_trivially_assignable<A, B>::value;

  template <class A, class B>
  concept bool NothrowAssignable = std::is_nothrow_assignable<A, B>::value;

  template <class A>
  concept bool CopyAssignable = Assignable<A&, const A&>;

  template <class A>
  concept bool TriviallyCopyAssignable = TriviallyAssignable<A&, const A&>;

  template <class A>
  concept bool NothrowCopyAssignable = NothrowAssignable<A&, const A&>;

  template <class A>
  concept bool MoveAssignable = Assignable<A&, A&&>;

  template <class A>
  concept bool TriviallyMoveAssignable = TriviallyAssignable<A&, A&&>;

  template <class A>
  concept bool NothrowMoveAssignable = NothrowAssignable<A&, A&&>;

  template <class A>
  concept bool Destructible = std::is_destructible<A>::value;

  template <class A>
  concept bool TriviallyDestructible = std::is_trivially_destructible<A>::value;

  template <class A>
  concept bool NothrowDestructible = std::is_nothrow_destructible<A>::value;

  template <class A>
  concept bool VirtualDestructor = std::has_virtual_destructor<A>::value;

  template <class A, class B>
  concept bool Same = std::is_same<A, B>::value;

  template <class A, class B>
  concept bool Derived = std::is_base_of<B, A>::value;

  template <class A, class B>
  concept bool Convertible = std::is_convertible<A, B>::value;

  // Other concepts
  template <class A>
  concept bool ConstReference = __helper::is_const_reference<A>::value;

  template <class A>
  concept bool Moveable = Object<A> && MoveConstructible<A> && MoveAssignable<A>;

  template <class A>
  concept bool TriviallyMoveable = Object<A> && TriviallyMoveConstructible<A> && TriviallyMoveAssignable<A>;

  template <class A>
  concept bool NotrhowMoveable = Object<A> && NothrowMoveConstructible<A> && NothrowMoveAssignable<A> && NothrowDestructible<A>;

  template <class A>
  concept bool Copyable = Object<A> && CopyConstructible<A> && CopyAssignable<A>;

  template <class A>
  concept bool TriviallyCopyable = Object<A> && TriviallyCopyConstructible<A> && TriviallyCopyAssignable<A>;

  template <class A>
  concept bool NothrowCopyable = Object<A> && NothrowCopyConstructible<A> && NothrowCopyAssignable<A>;

  template <class A, class B>
  concept bool Compatible = Convertible<A, B> && Convertible<B, A>;

  template <class... Args>
  concept bool Common = requires() {
    typename std::common_type<Args...>::type;
  };

  template <class... Args>
  using CommonType = typename std::common_type<Args...>::type;

  template <class F, class... Args>
  concept bool Callable = requires(F f, Args... args) {
    f(args...);
  };

  template <class F, class... Args>
  concept bool FunctionObject = Object<F> && Callable<F, Args...>;

  template <class F, class... Args>
  concept bool Predicate = requires(F f, Args... args) {
    f(args...) -> Boolean;
  };

  template <class F, class A>
  concept bool UnaryPredicate = Predicate<F, A>;

  template <class F, class A, class B>
  concept bool BinaryPredicate = Predicate<F, A, B>;

  template <class F, class... Args>
  concept bool Operator = Callable<F, Args...> && requires(F f, Args... args) {
    requires !Void<decltype(f(args...))>;
  };

  template <class P>
  concept bool Dereferenceable = Object<P> && requires(P p) {
    *p;
    requires Reference<decltype(*p)>;
  };

  template <class F, class A>
  concept bool UnaryOperator = Operator<F, A>;

  template <class F, class A, class B>
  concept bool BinaryOperator = Operator<F, A, B>;

  template <class A, class B = A>
  concept bool Swappable = requires(A a, B b) {
    __helper::__swap(a, b);
  };

  template <class A, class B = A>
  concept bool NothrowSwappable = requires(A a, B b) {
    {__helper::__swap(a, b)} noexcept;
  };

  template <class A, class B = A>
  concept bool ValueSwappable = Dereferenceable<A> && Dereferenceable<B> && requires(A a, B b) {
    requires Swappable<decltype(*a), decltype(*b)>;
  };

  template <class A, class B = A>
  concept bool NothrowValueSwappable = Dereferenceable<A> && Dereferenceable<B> && requires(A a, B b) {
    requires NothrowSwappable<decltype(*a), decltype(*b)>;
  };

  namespace __helper {
    template <class A, class B = A>
    concept bool __EqualityComparable = requires(A a, B b) {
      {a == b} -> Boolean;
    };
  }
  template <class A, class B = A>
  concept bool EqualityComparable = __helper::__EqualityComparable<A>    && __helper::__EqualityComparable<B>   &&
                                    __helper::__EqualityComparable<A, B> && __helper::__EqualityComparable<B, A>;

  namespace __helper {
    template <class A, class B = A>
    concept bool __LessThanComparable = requires(A a, B b) {
      {a < b} -> Boolean;
    };
  }
  template <class A, class B = A>
  concept bool LessThanComparable = __helper::__LessThanComparable<A>    && __helper::__LessThanComparable<B>   &&
                                    __helper::__LessThanComparable<A, B> && __helper::__LessThanComparable<B, A>;

  namespace __helper {
    template <class A, class B = A>
    concept bool __Comparable = requires(A a, B b) {
      {a == b} -> Boolean;
      {a != b} -> Boolean;
    };
  }
  template <class A, class B = A>
  concept bool Comparable = __helper::__Comparable<A>    && __helper::__Comparable<B>   &&
                            __helper::__Comparable<A, B> && __helper::__Comparable<B, A>;

  namespace __helper {
    template <class A, class B = A>
    concept bool __Ordered = requires(A a, B b) {
      {a <  b} -> Boolean;
      {a <= b} -> Boolean;
      {a >  b} -> Boolean;
      {a >= b} -> Boolean;
    };
  }
  template <class A, class B = A>
  concept bool WeaklyOrdered =  __helper::__Ordered<A>    && __helper::__Ordered<B>   &&
                          __helper::__Ordered<A, B> && __helper::__Ordered<B, A>;

  template <class A, class B = A>
  concept bool Ordered = WeaklyOrdered<A, B> && Comparable<A, B>;

  template <class A>
  concept bool PreIncrementable = requires(A a) {
    {++a} -> A&;
  };

  template <class A>
  concept bool PostIncrementable = requires(A a) {
    {a++} -> A;
  };

  template <class A>
  concept bool Incrementable = PreIncrementable<A> && PostIncrementable<A>;

  template <class A>
  concept bool PreDecrementable = requires(A a) {
    {--a} -> A&;
  };

  template <class A>
  concept bool PostDecrementable = requires(A a) {
    {a--} -> A;
  };

  template <class A>
  concept bool Decrementable = PreDecrementable<A> && PostDecrementable<A>;

  template <class I>
  concept bool Iterator = Object<I> && CopyConstructible<I> && CopyAssignable<I> && Destructible<I> && Swappable<I> &&
                          Dereferenceable<I> && PreIncrementable<I>;

  template <class I>
  concept bool MutableIterator = Iterator<I> && requires(I i) {
    requires !ConstReference<decltype(*i)>;
  };

  template <class I>
  concept bool ConstIterator = Iterator<I> && requires(I i) {
    requires ConstReference<decltype(*i)>;
  };

  template <class I>
  concept bool OutputIterator = MutableIterator<I>;

  template <class I>
  concept bool InputIterator = Iterator<I> && Comparable<I>;

  template <class I>
  concept bool MutableInputIterator = MutableIterator<I> && InputIterator<I>;

  template <class I>
  concept bool ConstInputIterator = ConstIterator<I> && InputIterator<I>;

  template <class I>
  concept bool ForwardIterator = InputIterator<I> && Incrementable<I> && DefaultConstructible<I>;

  template <class I>
  concept bool MutableForwardIterator = MutableIterator<I> && ForwardIterator<I>;

  template <class I>
  concept bool ConstForwardIterator = ConstIterator<I> && ForwardIterator<I>;

  template <class I>
  concept bool BidirectionnalIterator = ForwardIterator<I> && Decrementable<I>;

  template <class I>
  concept bool MutableBidirectionnalIterator = MutableIterator<I> && BidirectionnalIterator<I>;

  template <class I>
  concept bool ConstBidirectionnalIterator = ConstIterator<I> && BidirectionnalIterator<I>;

  template <class I>
  concept bool RandomAccessIterator = BidirectionnalIterator<I> && Ordered<I> && requires(I i1, I i2, typename std::iterator_traits<I>::difference_type n) {
    {i2 - i1} -> typename std::iterator_traits<I>::difference_type;
    {i1 +  n} -> I;
    {n  + i1} -> I;
    {i1 -  n} -> I;
    {i1 += n} -> I;
    {i1 -= n} -> I;
    i1[n];
    requires Reference<decltype(i1[n])>;
  };

  template <class I>
  concept bool MutableRandomAccessIterator = MutableIterator<I> && RandomAccessIterator<I>;

  template <class I>
  concept bool ConstRandomAccessIterator = ConstIterator<I> && RandomAccessIterator<I>;



  namespace __helper {
    template <class A, class B = A>
    concept bool __ArithmeticAdd = requires(A a, B b) {
      {+a} -> A;
      {-a} -> A;
      {a + b} -> CommonType<A, B>;
      {a - b} -> CommonType<A, B>;
      {a += b} -> A&;
      {a -= b} -> A&;
    };
  }
  template <class A, class B = A>
  concept bool ArithmeticAdd =  __helper::__ArithmeticAdd<A>    && __helper::__ArithmeticAdd<B>   &&
                                __helper::__ArithmeticAdd<A, B> && __helper::__ArithmeticAdd<B, A>;

  template <class A, class B = A>
  concept bool CompatibleArithmeticAdd =  __helper::__ArithmeticAdd<A>   && __helper::__ArithmeticAdd<B> &&
                                          __helper::__ArithmeticAdd<A, B>;

  namespace __helper {
    template <class A, class B = A>
    concept bool __ArithmeticMul = requires(A a, B b) {
      {a *  b} -> CommonType<A, B>;
      {a /  b} -> CommonType<A, B>;
      {a *= b} -> A&;
      {a /= b} -> A&;
    };
  }
  template <class A, class B = A>
  concept bool ArithmeticMul =  __helper::__ArithmeticMul<A>    && __helper::__ArithmeticMul<B>   &&
                                __helper::__ArithmeticMul<A, B> && __helper::__ArithmeticMul<B, A>;

  template <class A, class B = A>
  concept bool CompatibleArithmeticMul =  __helper::__ArithmeticMul<A>   && __helper::__ArithmeticMul<B> &&
                                          __helper::__ArithmeticMul<A, B>;

  template <class A, class B = A>
  concept bool Arithmetic = ArithmeticAdd<A, B> && ArithmeticMul<A, B>;

  template <class A, class B = A>
  concept bool CompatibleArithmetic = CompatibleArithmeticAdd<A, B> && CompatibleArithmeticMul<A, B>;

  namespace __helper {
    template <class A, class B = A>
    concept bool __Bitmask = requires(A a, B b) {
      {~a} -> A;
      {a |  b} -> CommonType<A, B>;
      {a &  b} -> CommonType<A, B>;
      {a ^  b} -> CommonType<A, B>;
      {a |= b} -> A&;
      {a &= b} -> A&;
      {a ^= b} -> A&;
    };
  }
  template <class A, class B = A>
  concept bool Bitmask =  __helper::__Bitmask<A>    && __helper::__Bitmask<B>   &&
                          __helper::__Bitmask<A, B> && __helper::__Bitmask<B, A>;

  template <class A>
  concept bool ShiftableBitmask = Bitmask<A> && requires(A a) {
    {a << 1} -> A;
    {a >> 1} -> A;
    {a <<= 1} -> A&; 
    {a >>= 1} -> A&; 
  };

  template <class C>
  concept bool Container = Array<C> || (Object<C> && DefaultConstructible<C> && CopyConstructible<C> && Destructible<C> &&
                                        CopyAssignable<C> && Comparable<C> && Swappable<C> && requires(C c) {
    typename C::value_type;
    typename C::reference;
    typename C::const_reference;
    typename C::iterator;
    typename C::const_iterator;
    typename C::difference_type;
    typename C::size_type;
    {c.size()} -> typename C::size_type;
    {c.max_size()} -> typename C::size_type;
    {c.empty()} -> Boolean;
    {c.begin()} -> typename C::iterator;
    {c.end()} -> typename C::iterator;
    {c.cbegin()} -> typename C::const_iterator;
    {c.cend()} -> typename C::const_iterator;
    requires InputIterator<typename C::iterator>;
    requires ConstInputIterator<typename C::const_iterator>;
  });

  template <class C>
  concept bool ReversibleContainer = Array<C> || (Container<C> && requires(C c) {
    typename C::reverse_iterator;
    typename C::const_reverse_iterator;
    {c.rbegin()} -> typename C::reverse_iterator;
    {c.rend()} -> typename C::reverse_iterator;
    {c.crbegin()} -> typename C::const_reverse_iterator;
    {c.crend()} -> typename C::const_reverse_iterator;
    requires InputIterator<typename C::reverse_iterator>;
    requires ConstInputIterator<typename C::const_reverse_iterator>;
  });

  template <class A>
  concept bool Allocator = Object<A> && Moveable<A> && Copyable<A> && Comparable<A> && requires(A a) {
    typename A::value_type;
    typename std::allocator_traits<A>::pointer;
    typename std::allocator_traits<A>::const_pointer;
    typename std::allocator_traits<A>::void_pointer;
    typename std::allocator_traits<A>::value_type;
    typename std::allocator_traits<A>::size_type;
    typename std::allocator_traits<A>::difference_type;
  } && requires(A a, typename std::allocator_traits<A>::pointer ptr) {
    {a.allocate(1)} -> typename std::allocator_traits<A>::pointer;
    a.deallocate(ptr, 1);
  } &&
    MutableRandomAccessIterator<typename std::allocator_traits<A>::pointer> &&
      ConstRandomAccessIterator<typename std::allocator_traits<A>::const_pointer>
  ;
  
  template <class H, class K>
  concept bool Hash = CopyConstructible<H> && Destructible<H> && requires(H h, K k) {
    {h(k)} -> std::size_t;
  };
}
#endif //CONCEPTS_H
