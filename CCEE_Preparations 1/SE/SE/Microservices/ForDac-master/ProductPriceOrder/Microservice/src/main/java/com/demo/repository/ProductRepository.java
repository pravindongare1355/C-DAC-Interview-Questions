package com.demo.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.jpa.repository.JpaRepository;

import com.demo.entity.Product;

public interface ProductRepository extends JpaRepository<Product,Long> {

	Optional<List<Product>> findByCategory(String category);

}
