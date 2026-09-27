FROM gcc:13 AS build

RUN apt-get update -qq \
    && apt-get install -y -qq --no-install-recommends cmake git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF \
    && cmake --build build --parallel

FROM debian:bookworm-slim
WORKDIR /app
COPY --from=build /app/build/tekbook_app /app/tekbook_app
USER 65532:65532
ENTRYPOINT ["/app/tekbook_app"]
