\ProvidesClass{slides}

\LoadClass[10pt]{beamer}

% packages
\usetheme{metropolis}
\usepackage[utf8]{inputenc}
\usepackage[portuges,brazil]{babel}
\usepackage{datetime}
\usepackage{appendixnumberbeamer}

\usepackage{tikz}
\usepackage{colortbl}
\usepackage{inconsolata}

\usepackage{booktabs}
\usepackage{tabularx}
\usepackage{multirow}
\usepackage[export]{adjustbox}
\usepackage[scale=2]{ccicons}

\usepackage{pgfplots}
\usepgfplotslibrary{dateplot}

\usepackage{xspace}
\usepackage{minted}
\usepackage{mdframed}
\usepackage{enumerate}

\usepackage{amsmath}
\usepackage{algorithm}
\usepackage[noend]{algpseudocode}

% Setup
\usetikzlibrary{calc}
\usefonttheme{professionalfonts}

\hypersetup{
    colorlinks=true,
    linkcolor=black,
    filecolor=black,      
    urlcolor=blue,
}

% New commands
\newcommand{\generatetoc}{
\begin{frame}{Sumário}
  \setbeamertemplate{section in toc}[sections numbered]
  \tableofcontents[hideallsubsections]
\end{frame}
}

\newcommand{\rawcode}[1]{\texttt{#1}}
\newcommand{\code}[2]{\mintinline{#1}{#2}}
\newcommand{\file}[1]{\texttt{\underline{#1}}}

\renewcommand{\theFancyVerbLine}{\tiny \texttt{\textcolor{gray}{\arabic{FancyVerbLine}}}}

\newcommand{\inputcode}[2]{\begin{mdframed}[shadow=true,shadowsize=3pt,shadowcolor=gray]\inputminted[fontsize=\footnotesize,linenos,numbersep=4pt]{#1}{#2}\end{mdframed}}

\newcommand{\inputsnippet}[4]{\begin{mdframed}[shadow=true,shadowsize=3pt,shadowcolor=gray]\inputminted[fontsize=\footnotesize,linenos,firstline=#2,lastline=#3,numbersep=2pt]{#1}{#4}\end{mdframed}}

\newcommand{\inputsyntax}[2]{\inputminted[fontsize=\footnotesize]{#1}{#2}}

\newcommand{\vv}[1]{\vec{\mkern0mu#1}}
\newcommand{\Mod}[2]{#1\ (\mbox{mod}\ #2)}
\newcommand{\dist}{\mathrm{dist}}

\DeclareMathSymbol{\mlq}{\mathord}{operators}{``}
\DeclareMathSymbol{\mrq}{\mathord}{operators}{`'}

\renewcommand*{\ALG@name}{Algoritmo}
\renewcommand{\algorithmicrequire}{\textbf{Input:}}
\renewcommand{\algorithmicensure}{\textbf{Output:}}
\newcommand{\forto}{\ \mbox{\bf to}\ }
\newcommand{\algand}{\ \mbox{\bf and}\ }

\DeclareUnicodeCharacter{2229}{$\cap$}
\DeclareUnicodeCharacter{2205}{$\emptyset$}
\DeclareUnicodeCharacter{2282}{$\subset$}
