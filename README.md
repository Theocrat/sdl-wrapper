# Convenient SDL Wrapper

Okay, I know that this one has been done to death, but hear me out.

## Motivation

I am a Python programmer. This means that I am used to the ease of highly 
convenient abstractions in my SDK libraries. In fact, I am kind of spoilt. I 
_do not_ like using libraries filled with pointers and functions that take in 
pointer arguments.

I also do not like having to write long, verbose variable names.

So I am trying to get into SDL now, and I realized that it contains both the
aforementioned qualities. The library is built for C and not C++, which means 
it has functions that take a pointer to an `SDL_Renderer` object and have long
names that start with `SDL_` and appear to be in Pascal case. And some of these
are probably macros, I haven't looked into them all too well.

These two attributes made me feel uncomfortable. I would very much prefer 
something more like `sdl.init()` than `SDL_Init(SDL_INIT_VIDEO)`. It is less of
a mouthful and less of a hassle. Of course, better yet, the entire 
initialization can just be inside a constructor.

So I decided to build this on my own. Its a big project, given the scale of what
I normally do, so I will do this in steps.

## Development Roadmap

My first goal is to build a simple wrapper just for the rendering part, so that 
I can draw any shape or text I like into an image or an animation. This can go
into simple tasks like building graphs, for instance.

Then, I can build interactions with user - event handling, for instance.

The third step onwards, I will look at the documentation of SDL and implement 
the more advanced stuff.

Step | Objective | Status
-- | -- | --
1 | Build a simple rendering library that draws geometric shapes and text | <font color="#496">In Progress</font>
2 | Build the interface for reading user inputs | <font color="#555">Pending</font>
3 | Build more sophisticated stuff | <font color="#555">Pending</font>

The [main.cc](main.cc) file should give you an idea of what I am going for. To
put it simply, I want an elegant, intuitive, and not-too-verbose API. It should
follow the Zen of Python, aside from using the Camel and Pascal cases over 
underscore-based casing.

## TODO

1. Write a documentation for the library.
2. Write a contribution guideline, for generous enthusiasts out there.
3. Look up other similar projects, and cite them. I would like to avoid blatant
   plagiarism.