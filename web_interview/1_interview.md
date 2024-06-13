<!-- @format -->

# What is http? Why we used http.

```
  "http" stands for: hypertext transfer protocol
  because it takes the information from internet and show to us,
  OR
  it is one way to communicate b/w the clients and server
```

# Diff b/w http and https?

```
    Main difference is https is secured and most of browser used https, but not secured in http

    Ex: Whatever we have searched in google or chrome it is actually secured no one is able to see what you have searched
```

# Difference between tag and element in HTML?

```
    Tags are primary components of html.
    HTML tags are the starting and ending part of your HTML element.
    HTML element consist of both opening and closing tag and also consist the content inside in it

    Ex: <h1>Hello</h1>
    <h1></h1> => tag
    <h1>Hello</h1> => element
```

# Can we show a html page inside another html page..?

```
  Yes, we can show html page inside html page using "iframe" tag
  <iframe src"path of another file"> </iframe>
```

# What are void elements in html?

```
  Those elements which don't have closing tag.
  Ex: <img /> <br />
```

# Advantage of collapsing multiple whitespace?

```
  If you provide multiple spaces in html then it treats as single space because browser collapse multiple spaces into single space.
```

# What are html Entities.?

```
  There are some reserved character which starts from "&" and also mapped to some character in html.
  Ex: <  => &lt;
      >  => &gt;
    ' '  => &nbsp;
```

# How many types of list in html.?

```
  There are 3 types of list
  1. Unordered list
  2. Ordered list
  3. Descriptive list

  Ex: <ul>
        <li> unordered list</li>
      </ul>
      <ol>
        <li>Ordered list</ol>
      </ol>
      <dl>
        <dt>Div element</dt>
        <dd>Block element</dd>
      </dl>
```

# What is CDN hoisting?

```
  Content delivery network it helps server to reduce latency.
```

# Different types of doctype.?

```
  1. Strict doctype
  2. Transitional doctype
  3. Frameset doctype
```

# Difference between visibility hidden and display none.?

```
  => Visibility hidden of any element then it takes space in html document when we apply display hidden then it will not take space of that element in document.
```

# Difference between figure and img tag int html..?

```
  <figure> tag is a self container in which it can store img ans its caption as well but in img tag we can only store picture or image.
```

# Difference between select and datalist.?

```
  In select tag provides the multiple option to user to select any one of them.
  but in datalist it can sugest to user to select an option.

  Ex: select => suppose a input tag contain the gender it gives you 2 option male and female then we have to select any one of them.

  <datalist> if we click on input tab then press any key and it show some suggestion to user then this is a datalist.
```

# Convert the below data into Tabular format in HTML5?

S.no., Language, Mostly used for
1, HTML, FrontEnd
2, CSS, FrontEnd
3, Python, BackEnd

```
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8" />
		<meta
			name="viewport"
			content="width=device-width, initial-scale=1.0" />
		<title>Document</title>
        <style>
            table, tr, td, th{
                border: 1px solid grey;
            }
        </style>
	</head>
	<body>

        <table cellpadding="10" cellspacing="20">
            <tr>
                <th>S.no.</th>
                <th>Language</th>
                <th>Mostly used for</th>
            </tr>
            <tr>
                <td>1.</td>
                <td>Html</td>
                <td>FrontEnd</td>
            </tr>
            <tr>
                <td>2.</td>
                <td>Css</td>
                <td>FrontEnd</td>
            </tr>
            <tr>
                <td>3.</td>
                <td>Python</td>
                <td>BackEnd</td>
            </tr>
        </table>
	</body>
</html>
```

# Difference between canvas and svg.?
```
  Canvas:
    It works in smaller surface.
    It can modified by script only.
    It is less scalable.
  
  Svg:
    It works in larger surface.
    It can modified by css and script.
    It is more scalable.
```

# Concept of Web-storage.?
```
  Web storage help to storing some of the static data into local storage so we don't have to fetch data from server everytime.
  It decrease load time and smooth user experience.
  
  Two types of data:
    1.Local storage 2.Session storage
    -> local storage is that storage if we open our browser its data come back but in case of session storage once we off the browser then the data will be deleted from your storage.
```