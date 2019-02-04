# Updating the Arduino release

Follow these steps:

- Set the new version number
```bash
export VERSION=v0.0.4
```

- Tag a release as the new version and make it a release on GitHub
```bash
git tag ${VERSION?}
```

- Download the newly-generated archive and get the size and sha256
```bash
wget https://github.com/candykingdom/firefly-v2-board/archive/${VERSION?}.tar.gz
sha256sum ${VERSION?}.tar.gz
ls -l ${VERSION?}.tar.gz
```

- Set the new `version`, `archiveFileName`, `size`, and `url` in
  `package_candykingdom_index.json`

- Commit changes and push
