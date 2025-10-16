<h1 align="center">
	Fract-ol
</h1>
<p align="center">
	An awesome program that displays some fractals using the minilibx
</p>

## 📊 How it works ?
The point of this project is to displays some fractals using the minilibx, a library that simplify the use of the X Window System.  
Basically, the program iterates on each pixel of the window and go through the fractal's equation multiple times (the more you iterate the more the fractal will be "precise")  
Each pixel is somewhat mapped to a geometric plan so we can think of it like each pixel is a point of the plan.  
Doing this for each pixel and watching at which iteration the point "escapes" will define the color of the pixel.
All the points that, through the multiple iterations on the equation, converges (stays in the range of 2 from the origin of the plan) are colored in black. 
I implemented 4 fractals : Mandelbrot, Julias, Burningship and Pheonix.  
Julia and Pheonix are sets of fractals that takes arguments that will define their look.

I passed this project with the maximum grade of 125% (without the MacOS DIY)

## 🖐️ How to use ? 
Git clone the repo, make and you're done !\
The program should work on Linux and MacOS but has some leaks on MacOS that I dont want to fix (maybe later ?)  
Doing ```./fractol``` will show you all possible input.  
When the program is launched, press `h` to see controls.  

## 🏞️ Cool Screenshots
![0](https://github.com/EliotGrd/42fract-ol/blob/main/screenshots/0.png)
![1](https://github.com/EliotGrd/42fract-ol/blob/main/screenshots/1.png) 
![2](https://github.com/EliotGrd/42fract-ol/blob/main/screenshots/2.png)
![3](https://github.com/EliotGrd/42fract-ol/blob/main/screenshots/3.png)
