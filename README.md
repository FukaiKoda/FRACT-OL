# fract-ol - Interactive Fractal Generator

## 📌 Overview

fract-ol is a graphical project that generates and visualizes fractals using **imaginary numbers** and the **MiniLibX** graphical library. It allows users to explore famous fractals like the **Mandelbrot set** and **Julia set**, with interactive controls for zooming, panning, and modifying fractal parameters in real-time.

This project deepened my understanding of **complex numbers**, recursion, and graphical programming using **MiniLibX**.

## 📂 Features

### ✨ Fractal Generation

- **Mandelbrot Set**: Displays the classic fractal by iterating the function:
  \(z_{n+1} = z_n^2 + c\)
  where \(c\) represents each pixel in the complex plane.
- **Julia Set**: Similar to Mandelbrot but with a fixed \(c\), creating various patterns.
- Other fractals can be implemented by modifying the iteration formula.

### 🖥️ Graphical Library - MiniLibX

- Uses **MiniLibX** for rendering fractals.
- Enables window creation, pixel manipulation, and event handling.

### 🎮 Interactive Controls

- **Mouse Events**:
  - Scroll to **zoom in/out** for deep fractal exploration.
  - Click to modify the Julia set dynamically.
- **Keyboard Hooks**:
  - Arrow keys to **move** across the fractal.
  - `ESC` to **exit** the program.
  - Additional keys to adjust iterations, colors, and fractal parameters.

## 🚀 Usage

Compile the program using:

```sh
make
```

Run with the desired fractal:

```sh
./fractol mandelbrot
./fractol julia <real_part> <imaginary_part>
```

Example for a custom Julia set:

```sh
./fractol julia -0.7 0.27015
```

## 🎯 Key Takeaways

- Gained experience in **imaginary number calculations** and **complex plane mapping**.
- Developed real-time **graphical rendering** and **event handling** using MiniLibX.
- Implemented **interactive controls** for a better fractal exploration experience.

## 🎁 Bonus - Burning Ship Fractal

- **Burning Ship Fractal**: A variation of the Mandelbrot set, using the formula:
  \(z_{n+1} = (|Re(z_n)| + i|Im(z_n)|)^2 + c\)
  where the real and imaginary parts are taken in absolute value before squaring.
- Creates a distinctive "flame-like" pattern with sharp, ship-like structures.
- Fully interactive with zoom, pan, and iteration adjustments.
- Run it with:
  ```sh
  ./fractol burningship
  ```

## 📜 License

This project is open-source and available under the MIT License.

