# ImageToDesmos

1. Place the image you want to convert in the same directory as the Dockerfile
2. Edit the Dockerfile to copy the image to the container
3. Change the C++ program's arguments to match your image's name
4. Run the following commands:

```bash
# Build the Docker image
docker build -t imagetodesmos .
```

```bash
# Run the Docker image
docker run imagetodesmos
```

```bash
# Get only the ID of the most recent container ID
docker ps -l -q
```

```bash
# Copy the output file from the container to the host
docker cp $(docker ps -l -q):/app ./output
```
