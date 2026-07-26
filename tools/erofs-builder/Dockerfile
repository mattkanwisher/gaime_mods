# erofs-utils built with SELinux + Android support.
#
# The Homebrew build has neither --file-contexts nor --fs-config-file, because
# both need libselinux, which does not exist on macOS. Without them any rebuilt
# system image loses every SELinux label and uid/gid and will not boot.
#
# AOSP builds EROFS images from a plain directory plus a file_contexts file and
# an fs_config file, which is exactly what these options do — so the container
# filesystem does not need to carry security.* xattrs itself.
FROM debian:bookworm

RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential autoconf automake libtool pkg-config git ca-certificates \
        liblz4-dev zlib1g-dev liblzma-dev libselinux1-dev uuid-dev \
        e2fsprogs android-sdk-libsparse-utils python3 \
    && rm -rf /var/lib/apt/lists/*

RUN git clone --depth 1 https://git.kernel.org/pub/scm/linux/kernel/git/xiang/erofs-utils.git /src

WORKDIR /src
RUN ./autogen.sh \
    && ./configure --with-selinux --with-uuid --enable-lz4 --enable-lzma \
    && make -j"$(nproc)" \
    && make install

WORKDIR /work
CMD ["/bin/bash"]
