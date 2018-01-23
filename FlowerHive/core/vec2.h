//
//  vec2.h
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 11..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef vec2_h
#define vec2_h

template <class T> struct tvec2
{
    union{ struct { T r, g; }; struct { T x, y; }; };
    
    // constructor/set
    tvec2(){ x=y=0; }
    tvec2( T a ){ x=y=a; }                        inline void set( T a ){ x=y=a; }
    tvec2( T a, T b ){ x=a;y=b; }                inline void set( T a, T b ){ x=a;y=b; }
    tvec2( const tvec2& v ){ x=v.x;y=v.y; }        inline void set( const tvec2& v ){ x=v.x;y=v.y; }
    tvec2( const T* a ){ x=a[0];y=a[1]; }        inline void set( const T* a ){ x=a[0];y=a[1]; }
    
    // assignment
    inline tvec2& operator=( T a ){ set(a); return *this; }
    inline tvec2& operator+=( const tvec2& v ){ x+=v.x; y+=v.y; return *this; }
    inline tvec2& operator-=( const tvec2& v ){ x-=v.x; y-=v.y; return *this; }
    inline tvec2& operator*=( const tvec2& v ){ x*=v.x; y*=v.y; return *this; }
    inline tvec2& operator/=( const tvec2& v ){ x/=v.x; y/=v.y; return *this; }
    inline tvec2& operator+=( T a ){ x+=a; y+=a; return *this; }
    inline tvec2& operator-=( T a ){ x-=a; y-=a; return *this; }
    inline tvec2& operator*=( T a ){ x*=a; y*=a; return *this; }
    inline tvec2& operator/=( T a ){ x/=a; y/=a; return *this; }
    
    // casting
    inline operator T*(){ return &x; }
    inline operator const T*() const { return &x; }
    
    // array operator
    inline T& operator[]( int i ){ return (&r)[i]; }
    inline const T& operator[]( int i ) const { return (&r)[i]; }
    inline T& at( int i ){ return (&r)[i]; }
    inline const T& at( int i ) const { return (&r)[i]; }
    
    // unary operators
    inline tvec2 operator+(){ return tvec2(r, g); }
    inline tvec2 operator+() const { return tvec2(r, g); }
    inline tvec2 operator-(){ return tvec2(-r, -g); }
    inline tvec2 operator-() const { return tvec2(-r, -g); }
    
    // binary operators
    inline tvec2 operator+( const tvec2& v ) const { return tvec2(r+v.r, g+v.g); }
    inline tvec2 operator-( const tvec2& v ) const { return tvec2(r-v.r, g-v.g); }
    inline tvec2 operator*( const tvec2& v ) const { return tvec2(r*v.r, g*v.g); }
    inline tvec2 operator/( const tvec2& v ) const { return tvec2(r/v.r, g/v.g);  }
    inline tvec2 operator+( T a ) const { return tvec2(r+a, g+a); }
    inline tvec2 operator-( T a ) const { return tvec2(r-a, g-a); }
    inline tvec2 operator*( T a ) const { return tvec2(r*a, g*a); }
    inline tvec2 operator/( T a ) const { return tvec2(r/a, g/a); }
    
    // length, normalize, dot product
    inline T length(){ return (T)(sqrt(r*r+g*g)); }
    inline T length2(){ return (T)(r*r+g*g); }
    inline T dot( const tvec2& v ) const { return (T)(r*v.r+g*v.g); }
    inline tvec2 normalize(){ return tvec2(r, g)/length(); }
};



typedef tvec2<int> ivec2;
typedef tvec2<float> fvec2;
typedef tvec2<double> dvec2;


#endif /* vec2_h */
