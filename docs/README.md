# Updating the Arduino release

Follow these steps:

- Set the new version number
```bash
export VERSION=v0.0.5
```

- Tag a release as the new version
```bash
git tag ${VERSION?}
git push origin ${VERSION?}
```

- Make it [release on GitHub](https://github.com/candykingdom/firefly-v2-board/releases)

- Download the newly-generated archive and get the size and sha256
```bash
wget https://github.com/candykingdom/firefly-v2-board/archive/${VERSION?}.tar.gz
sha256sum ${VERSION?}.tar.gz
ls -l ${VERSION?}.tar.gz
```

- Set the new `version`, `archiveFileName`, `size`, and `url` in
  `package_candykingdom_index.json`

- Commit changes and push

# File format documentation

https://github.com/arduino/Arduino/wiki/Arduino-IDE-1.6.x-package_index.json-format-specification
