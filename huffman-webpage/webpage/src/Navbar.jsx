import React from "react";
import githubLogoR from "./assets/githubLogo.jpg";
import logoUiE from "../src/assets/logoUie.svg";
import logo_xGeN02 from "../src/assets/logo-color.png";
import "./Navbar.css"

const Navbar = () => {
  return (
    <header>
      <h1 className="project-title">Huffman Codification</h1>
      <div className="subject-logos">
        <div className="github">
          <a
            href="https://github.com/0xGeN02"
            target="_blank"
            rel="noopener noreferrer"
            aria-label="GitHub profile"
          >
            <img src={githubLogoR} alt="github" />
          </a>
        </div>
        <div className="myLogo">
          <a href="https://0xgen02.github.io"
                target="_blank"
                rel="noopener noreferrer"
          >
            <img src={logo_xGeN02} alt="xGeN02" />
          </a>
        </div>
        <div className="UiE">
            <a
              href="https://uie.edu"
              target="_blank"
              rel="noopener noreferrer"
              aria-label="University website"
            >
              <img src={logoUiE} alt="logoUiE" />
            </a>
          </div>
      </div>
    </header>
  );
};

export default Navbar;
