<!-- @format -->
## CSS

# Describe units in css..?

```
  There are several units in css:-
  1. Absolute unit
  2. Relative unit
  3. Percentage unit

  1. Absolute unit:- [px, pt, in, mm, cm]
    => They all are fixed unit it will take same size as you mention there is no restrictions are there.

  2. Relative unit:- [%, em, rem] or [vh, vw]
  => They all are relative unit it takes the width or height to their respective parent like: it no parent then consider body as a parent.

  em: It is a special case like its parent depends on any other parent then it takes it multiple of it
    <div style="font-size: 2em;">
        <div style="font-size: 2em;">
            <div style="font-size: 2em;">hello</div>
            <div>Hey</div>
        </div>
    </div>
    => In above case hello having fint-size as 8em

    rem: In case of rem it will fully dependent on its above parent it will take height width to consider them same as percentage also

    OR

    [vh, vw] => They both are taking size with respect to document

```

# Disadvantage of css?

```
  1. There is no parent selector in css.
  2. There are some tag which behave different in different browser.
```

# List diff. types of selector.?

```
  1. Element selector
  2. Class selector
  3. Id selector
  4. Attribute selector input [type="text"]
  5. Universal selector
  6. Child combinator
  7. Siblings combinator
  8. Descendant Combinator #combination .box{}
```

# How is border-box different from content-box?
```
    When using box-sizing: content-box; the content size remain same while border-box size grows as padding and border grow. but when using box-sizing: border-box; , the size of border-box remains same while size of content decreases as padding and border grow.
```

# When does DOM reflow occur?
```
  1. Modify content on the page, e.g. the text in an input box.
  2. Insert new element or delete an element.
  3. Animate a dom element.
  4. Changing css.