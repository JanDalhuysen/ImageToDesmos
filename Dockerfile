FROM ubuntu:22.04

RUN apt update

RUN DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC apt-get -y install tzdata

RUN apt install -y g++
RUN apt install -y git
RUN apt install -y wget
RUN apt install -y curl
RUN apt install -y cmake
RUN apt install -y unzip
RUN apt install -y build-essential
RUN apt install -y neofetch
RUN apt install -y default-jre
RUN apt install -y potrace
RUN apt install -y imagemagick

RUN wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
RUN unzip opencv.zip

RUN mkdir -p build && cd build

RUN cd build && cmake  ../opencv-4.x
RUN cd build && cmake --build . -j $(nproc)

RUN cd build && make install

WORKDIR /app

COPY CMakeLists.txt /app

COPY ImageToDesmos.cpp /app

COPY opencv.cpp /app

COPY svgeq-release.jar /app

COPY arch.png /app

RUN cmake .
RUN make
RUN g++ ImageToDesmos.cpp -o ImageToDesmos
RUN ./ImageToDesmos arch.png
