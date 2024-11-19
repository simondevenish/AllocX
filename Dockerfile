# Use a stable base image
FROM ubuntu:22.04

# Set environment variables to minimise interaction during installation
ENV DEBIAN_FRONTEND=noninteractive
ENV LANG=C.UTF-8
ENV LC_ALL=C.UTF-8
ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++
ENV VIRTUAL_ENV=/venv
ENV PATH="$VIRTUAL_ENV/bin:$PATH"

# Install core development tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-11 \
    g++-11 \
    cmake \
    python3 \
    python3-pip \
    python3-venv \
    clang-format \
    git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Set GCC/G++ version explicitly
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 100

# Create a workspace directory
WORKDIR /workspace

# Copy the entire project into the container
COPY . .

# Create and activate Python virtual environment
RUN python3 -m venv /venv
RUN pip install --no-cache-dir pytest

# Ensure required scripts are executable (if applicable)
RUN chmod +x scripts/* || true

# Build the project using CMake
RUN cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build

# Default command for development
CMD ["/bin/bash"]