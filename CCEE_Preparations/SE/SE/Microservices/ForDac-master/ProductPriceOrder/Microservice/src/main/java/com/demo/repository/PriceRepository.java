package com.demo.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import com.demo.entity.Price;

public interface PriceRepository extends JpaRepository<Price,Long> {

}
