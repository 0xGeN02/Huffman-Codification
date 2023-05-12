import React from "react";
import "./Hero.css";
function Hero({ children }) {
  return (
    <section className="hero">
      <div className="hero-container">
        <h1 className="hero-title">Codification with C++ && WASM</h1>
        {children}
      </div>
    </section>
  );
}

export default Hero;